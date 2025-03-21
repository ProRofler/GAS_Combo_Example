// GAS Example project

#include "GAS/GASEAbilityBase.h"
#include "Characters/GASEBaseCharacter.h"
#include "Logging/StructuredLog.h"

UGASEAbilityBase::UGASEAbilityBase() { InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor; }

void UGASEAbilityBase::OnGiveAbility(const FGameplayAbilityActorInfo *ActorInfo, const FGameplayAbilitySpec &Spec)
{
     Super::OnGiveAbility(ActorInfo, Spec);

    if (GetInstancingPolicy() == EGameplayAbilityInstancingPolicy::NonInstanced)
        checkf(false, TEXT("This ability can't be non-instanced!"));

    if (const FGameplayAbilityActorInfo *OwnerActorInfo = GetCurrentActorInfo())
        OwnerCharacter = CastChecked<AGASEBaseCharacter>(OwnerActorInfo->AvatarActor);
}

void UGASEAbilityBase::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                       const FGameplayAbilityActorInfo *ActorInfo,
                                       const FGameplayAbilityActivationInfo ActivationInfo,
                                       const FGameplayEventData *TriggerEventData)
{
    if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
    }

     Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    if (bEnableLogging)
        UE_LOGFMT(LogTemp, Display, "Ability'{AbilityName}' was activated", ("AbilityName", this->GetName()));
}

void UGASEAbilityBase::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo *ActorInfo,
                                  const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility,
                                  bool bWasCancelled)
{
     Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

    if (bEnableLogging)
        UE_LOGFMT(LogTemp, Display, "Ability'{AbilityName}' was deactivated", ("AbilityName", this->GetName()));
}
