const addon = require('../build/Release/dnf_calculator_addon-native');

interface IDnfCalculatorAddonNative
{
    greet(strName: string): string;
};

export class DnfCalculatorAddon {
    constructor(name: string) {
        this._addonInstance = new addon.DnfCalculatorAddon(name)
    }

    greet (strName: string) {
        return this._addonInstance.greet(strName);
    }

    // private members
    private _addonInstance: IDnfCalculatorAddonNative;
}
