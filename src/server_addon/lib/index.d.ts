declare class DnfCalculatorAddon {
    constructor(name: string);

    greet(name: string): string;
    getWeaponJson(): object;
    getEquipmentJson(): object;
    getEquipmentSetJson(): object;
}

export { DnfCalculatorAddon };