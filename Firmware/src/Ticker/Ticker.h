/*
 * Ticker
 *
 * @file Ticker.h
 * @package Ticker
 *
 * @author Carsten Walther
 */

#ifndef TICKER_H
#define TICKER_H

#include <functional>
#include <Schedule.h>
#include <ets_sys.h>

class Ticker
{
    public:

        Ticker();
        ~Ticker();

        typedef void (*callback_with_arg_t)(void*);
        typedef std::function<void(void)> callback_function_t;

        void attach_scheduled(float seconds, callback_function_t callback) {
            _callback_function = [callback]() {
                    schedule_function(callback);
            };
            _attach_ms(1000UL * seconds, true);
        }

        void attach(float seconds, callback_function_t callback) {
            _callback_function = std::move(callback);
            _attach_ms(1000UL * seconds, true);
        }

        void attach_ms_scheduled(uint32_t milliseconds, callback_function_t callback) {
            _callback_function = [callback]() {
                schedule_function(callback);
            };
            _attach_ms(milliseconds, true);
        }

        void attach_ms(uint32_t milliseconds, callback_function_t callback) {
            _callback_function = std::move(callback);
            _attach_ms(milliseconds, true);
        }

        template<typename TArg>
        void attach(float seconds, void (*callback)(TArg), TArg arg) {
            static_assert(sizeof(TArg) <= sizeof(void*), "attach() callback argument size must be <= sizeof(void*)");
            _attach_ms(1000UL * seconds, true, reinterpret_cast<callback_with_arg_t>(callback), reinterpret_cast<void*>(arg));
        }

        template<typename TArg>
        void attach_ms(uint32_t milliseconds, void (*callback)(TArg), TArg arg) {
            static_assert(sizeof(TArg) <= sizeof(void*), "attach() callback argument size must be <= sizeof(void*)");
            _attach_ms(milliseconds, true, reinterpret_cast<callback_with_arg_t>(callback), reinterpret_cast<void*>(arg));
        }

        void once_scheduled(float seconds, callback_function_t callback) {
            _callback_function = [callback]() {
                schedule_function(callback);
            };
            _attach_ms(1000UL * seconds, false);
        }

        void once(float seconds, callback_function_t callback) {
            _callback_function = std::move(callback);
            _attach_ms(1000UL * seconds, false);
        }

        void once_ms_scheduled(uint32_t milliseconds, callback_function_t callback) {
            _callback_function = [callback]() {
                schedule_function(callback);
            };
            _attach_ms(milliseconds, false);
        }

        void once_ms(uint32_t milliseconds, callback_function_t callback) {
            _callback_function = std::move(callback);
            _attach_ms(milliseconds, false);
        }

        template<typename TArg>
        void once(float seconds, void (*callback)(TArg), TArg arg) {
            static_assert(sizeof(TArg) <= sizeof(void*), "attach() callback argument size must be <= sizeof(void*)");
            _attach_ms(1000UL * seconds, false, reinterpret_cast<callback_with_arg_t>(callback), reinterpret_cast<void*>(arg));
        }

        template<typename TArg>
        void once_ms(uint32_t milliseconds, void (*callback)(TArg), TArg arg) {
            static_assert(sizeof(TArg) <= sizeof(void*), "attach() callback argument size must be <= sizeof(void*)");
            _attach_ms(milliseconds, false, reinterpret_cast<callback_with_arg_t>(callback), reinterpret_cast<void*>(arg));
        }

        void detach();
        bool active() const;

    protected:
        static void _static_callback(void* arg);
        void _attach_ms(uint32_t milliseconds, bool repeat, callback_with_arg_t callback, void* arg);
        void _attach_ms(uint32_t milliseconds, bool repeat) {
            _attach_ms(milliseconds, repeat, _static_callback, this);
        }

        ETSTimer* _timer;
        callback_function_t _callback_function = nullptr;

    private:
        ETSTimer _etsTimer;
};

#endif //TICKER_H