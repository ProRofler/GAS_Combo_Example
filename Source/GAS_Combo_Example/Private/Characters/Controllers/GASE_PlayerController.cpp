// GAS Example project

#include "Characters/Controllers/GASE_PlayerController.h"
#include "Characters/GASE_BaseCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AGASE_PlayerController::BeginPlay()
{
    Super::BeginPlay();

    ControllerSetup();
}

void AGASE_PlayerController::OnPossess(APawn *aPawn)
{

    Super::OnPossess(aPawn);

    if (UEnhancedInputComponent *Input = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        GASEPlayerCharacter = CastChecked<AGASE_BaseCharacter>(GetCharacter());

        Input->BindAction(InputData.MoveAction, ETriggerEvent::Triggered, GASEPlayerCharacter.Get(),
                          &AGASE_BaseCharacter::MoveAction);
        Input->BindAction(InputData.LookAction, ETriggerEvent::Triggered, GASEPlayerCharacter.Get(),
                          &AGASE_BaseCharacter::LookAction);
    }
}

void AGASE_PlayerController::ControllerSetup()
{

    if (APlayerController *PC = Cast<APlayerController>(this))
    {
        if (UEnhancedInputLocalPlayerSubsystem *Subsystem =
                ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            Subsystem->ClearAllMappings();
            Subsystem->AddMappingContext(InputData.InputMapping, 0);

            UE_LOG(LogTemp, Display, TEXT("Enhanced input mapping setup successfull"));
        }
    }
}