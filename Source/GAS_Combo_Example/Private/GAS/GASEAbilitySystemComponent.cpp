// GAS Example project

#include "GAS/GASEAbilitySystemComponent.h"
#include "DataAssets/GASEAbilitiesListDataAsset.h"

void UGASEAbilitySystemComponent::BeginPlay()
{
    Super::BeginPlay();

    InitAbilities();
}

void UGASEAbilitySystemComponent::AbilityInputTagPressed(const FGameplayTag InputTag)
{
    if (!InputTag.IsValid()) return;

    TryActivateAbilitiesByTag(InputTag.GetSingleTagContainer());
}

void UGASEAbilitySystemComponent::InitAbilities()
{

    InitAbilityActorInfo(GetOwner(), GetOwner());

    if (GrantedAbilitiesDataAsset)
    {
        if (!GrantedAbilitiesDataAsset->GrantedAbilities.IsEmpty())
        {
            for (auto &Ability : GrantedAbilitiesDataAsset->GrantedAbilities)
            {
                GiveAbility(FGameplayAbilitySpec(Ability, 1, 0, GetOwner()));
            }
        }
    }
}
