export interface ApiItemInfo {
    itemId: string;
    itemName: string;
    itemRarity: string;
    itemType: string;
    itemTypeDetail: string;
    itemAvaiableLevel: number;
    itemObtainInfo: string;
    itemExplain: string;
    itemExplainDetail: string;
    itemFlavorText: string;
    setItemId: string;
    setItemName: string;
    itemStatus: {name: string, value: number|string}[];
    itemBuff: {
        explain: string;
        explainDetail: string;
        reinforceSkill: {
            jobName: string;
            jobId: string;
            skills: {
                skillId: string;
                name: string;
                value: number;
            }[];
        }[];
    }
}