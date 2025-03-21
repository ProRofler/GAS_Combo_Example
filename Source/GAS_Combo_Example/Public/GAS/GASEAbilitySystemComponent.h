// GAS Example project

#pragma once

#include "AbilitySystemComponent.h"
#include "CoreMinimal.h"

#include "GASEAbilitySystemComponent.generated.h"

class UGASEAbilitiesListDataAsset;

UCLASS()
class GAS_COMBO_EXAMPLE_API UGASEAbilitySystemComponent : public UAbilitySystemComponent
{
    GENERATED_BODY()

  public:
    UFUNCTION(BlueprintCallable, Category = "GASE Input")
    void AbilityInputTagPressed(const FGameplayTag InputTag);

  private:
    void InitAbilities();

  protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GASE Abilities")
    TObjectPtr<UGASEAbilitiesListDataAsset> GrantedAbilitiesDataAsset;
};
