// GAS Example project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "GASE_PlayerController.generated.h"

class AGASE_BaseCharacter;
class UInputMappingContext;
class UInputAction;

USTRUCT(BlueprintType)
struct FEnhancedInputData
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mapping context")
    UInputMappingContext *InputMapping = nullptr;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
    UInputAction *MoveAction = nullptr;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
    UInputAction *LookAction = nullptr;
};

UCLASS()
class GAS_COMBO_EXAMPLE_API AGASE_PlayerController : public APlayerController
{
    GENERATED_BODY()

  public:
    virtual void BeginPlay() override;

  protected:
    virtual void OnPossess(APawn *aPawn) override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "_Enhanced input settings")
    FEnhancedInputData InputData;

  private:
    TWeakObjectPtr<AGASE_BaseCharacter> GASEPlayerCharacter;

    void ControllerSetup();
};
