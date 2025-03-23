// GAS Example project

#include "GAS/GASEMainAttributeSet.h"
#include "Characters/GASEBaseCharacter.h"
#include "GameplayEffectExtension.h"

void UGASEMainAttributeSet::PreAttributeChange(const FGameplayAttribute &Attribute, float &NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

    if (Attribute == GetHealthAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
    }
}

void UGASEMainAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData &Data)
{
    Super::PostGameplayEffectExecute(Data);

    const FGameplayEffectSpec &Spec = Data.EffectSpec;

    FGameplayTagContainer EffectTags;
    Spec.GetAllAssetTags(EffectTags);

    if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
        if (const auto GASECharacter = Cast<AGASEBaseCharacter>(Data.Target.GetAvatarActor()))
        {
            GASECharacter->OnHealthChanged.Broadcast(GetHealth(), EffectTags);
        }
    }
}
