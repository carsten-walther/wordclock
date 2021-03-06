/* eslint-disable */
/* tslint:disable */
/**
 * This is an autogenerated file created by the Stencil compiler.
 * It contains typing information for all components that exist in this project.
 */
import { HTMLStencilElement, JSXBase } from "@stencil/core/internal";
export namespace Components {
    interface AppAbout {
        "isDisabled": boolean;
    }
    interface AppColorPicker {
        "color": Color;
        "header": string;
    }
    interface AppHome {
        "isDisabled": boolean;
    }
    interface AppRoot {
    }
}
declare global {
    interface HTMLAppAboutElement extends Components.AppAbout, HTMLStencilElement {
    }
    var HTMLAppAboutElement: {
        prototype: HTMLAppAboutElement;
        new (): HTMLAppAboutElement;
    };
    interface HTMLAppColorPickerElement extends Components.AppColorPicker, HTMLStencilElement {
    }
    var HTMLAppColorPickerElement: {
        prototype: HTMLAppColorPickerElement;
        new (): HTMLAppColorPickerElement;
    };
    interface HTMLAppHomeElement extends Components.AppHome, HTMLStencilElement {
    }
    var HTMLAppHomeElement: {
        prototype: HTMLAppHomeElement;
        new (): HTMLAppHomeElement;
    };
    interface HTMLAppRootElement extends Components.AppRoot, HTMLStencilElement {
    }
    var HTMLAppRootElement: {
        prototype: HTMLAppRootElement;
        new (): HTMLAppRootElement;
    };
    interface HTMLElementTagNameMap {
        "app-about": HTMLAppAboutElement;
        "app-color-picker": HTMLAppColorPickerElement;
        "app-home": HTMLAppHomeElement;
        "app-root": HTMLAppRootElement;
    }
}
declare namespace LocalJSX {
    interface AppAbout {
        "isDisabled"?: boolean;
    }
    interface AppColorPicker {
        "color"?: Color;
        "header"?: string;
    }
    interface AppHome {
        "isDisabled"?: boolean;
    }
    interface AppRoot {
    }
    interface IntrinsicElements {
        "app-about": AppAbout;
        "app-color-picker": AppColorPicker;
        "app-home": AppHome;
        "app-root": AppRoot;
    }
}
export { LocalJSX as JSX };
declare module "@stencil/core" {
    export namespace JSX {
        interface IntrinsicElements {
            "app-about": LocalJSX.AppAbout & JSXBase.HTMLAttributes<HTMLAppAboutElement>;
            "app-color-picker": LocalJSX.AppColorPicker & JSXBase.HTMLAttributes<HTMLAppColorPickerElement>;
            "app-home": LocalJSX.AppHome & JSXBase.HTMLAttributes<HTMLAppHomeElement>;
            "app-root": LocalJSX.AppRoot & JSXBase.HTMLAttributes<HTMLAppRootElement>;
        }
    }
}
