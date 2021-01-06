interface DamageOption
{
    type: string;
    value: number;
}

interface SkillOption
{
    type: string;
    level_range: string;
    value: string;
}

interface Equipment
{
    id: string;
    type: string;
    set_id: string;
    is_mythic: boolean;
    damage_options: DamageOption[];
    skill_options: SkillOption[]
}