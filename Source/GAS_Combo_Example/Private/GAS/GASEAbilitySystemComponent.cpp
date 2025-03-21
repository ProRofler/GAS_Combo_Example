// GAS Example project

#include "GAS/GASEAbilitySystemComponent.h"
#include "Characters/GASEBaseCharacter.h"
#include "DataAssets/GASEAbilitiesListDataAsset.h"

void UGASEAbilitySystemComponent::BeginPlay() { Super::BeginPlay(); }

void UGASEAbilitySystemComponent::AbilityInputTagPressed(const FGameplayTag InputTag)
{
    if (!InputTag.IsValid()) return;

    TryActivateAbilitiesByTag(InputTag.GetSingleTagContainer());
}

void UGASEAbilitySystemComponent::InitAbilities()
{

    InitAbilityActorInfo(GetOwner(), GetOwner());

    if (auto grantedAbilitiesDA = Cast<AGASEBaseCharacter>(GetOwner())->GetGrantedAbilitiesDataAsset())
    {
        if (!grantedAbilitiesDA->GrantedAbilities.IsEmpty())
        {
            for (auto &Ability : grantedAbilitiesDA->GrantedAbilities)
            {
                GiveAbility(FGameplayAbilitySpec(Ability, 1, 0, GetOwner()));
            }
        }
    }
}
