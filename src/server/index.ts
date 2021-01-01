import { DnfCalculatorAddon } from "../server_addon/lib";

const addon = new DnfCalculatorAddon("skyser2003");
addon.greet("stranger");
const weaponJson = addon.getWeaponJson();
console.log(weaponJson);