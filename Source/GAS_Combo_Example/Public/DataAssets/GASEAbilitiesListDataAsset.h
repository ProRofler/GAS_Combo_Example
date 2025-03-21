// GAS Example project

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "GASEAbilitiesListDataAsset.generated.h"

UCLASS()
class GAS_COMBO_EXAMPLE_API UGASEAbilitiesListDataAsset : public UDataAsset
{
    GENERATED_BODY()
  public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SK Abilities|Granted abilities")
    TArray<TSubclassOf<class UGameplayAbility>> GrantedAbilities;
};
