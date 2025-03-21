// GAS Example project

#pragma once

#include "Abilities/GameplayAbility.h"
#include "CoreMinimal.h"

#include "GASEAbilityBase.generated.h"

class AGASEBaseCharacter;

UCLASS()
class GAS_COMBO_EXAMPLE_API UGASEAbilityBase : public UGameplayAbility
{
    GENERATED_BODY()

  public:
    UGASEAbilityBase();

    virtual void OnGiveAbility(const FGameplayAbilityActorInfo *ActorInfo, const FGameplayAbilitySpec &Spec);

    UFUNCTION(BlueprintCallable, Category = "GASE Getters")
    AGASEBaseCharacter *GetGASEOwnerCharacter() const { return OwnerCharacter; }

  protected:
    virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo *ActorInfo,
                                 const FGameplayAbilityActivationInfo ActivationInfo,
                                 const FGameplayEventData *TriggerEventData);

    virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo *ActorInfo,
                            const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility,
                            bool bWasCancelled);

  protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DEBUGGING")
    bool bEnableLogging = false;

  private:
    AGASEBaseCharacter *OwnerCharacter = nullptr;
};
