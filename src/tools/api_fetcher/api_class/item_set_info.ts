export interface ApiItemSetInfo
{
    setItemId: string;
    setItemName: string;
    setItems: {
        slotId: string;
        slotName: string;
        itemId: string;
        itemName: string;
        itemRarity: string;
    }[];
    setItemOption: {
        optionNo: number;
        explain: string;
        detailExplain: string;
        itemBuff: {
            explain: string;
            reinforceSkill: {
                jobId: string;
                jobName: string;
                skills: {
                    skillId: string;
                    name: string;
                    value: string;
                }[];
            }[];
        }
    }[];
}