// GAS Example project

#include "Characters/Controllers/GASEPlayerController.h"
#include "Characters/GASEBaseCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AGASEPlayerController::BeginPlay()
{
    Super::BeginPlay();

    ControllerSetup();
}

void AGASEPlayerController::OnPossess(APawn *aPawn)
{

    Super::OnPossess(aPawn);

    if (UEnhancedInputComponent *Input = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        GASEPlayerCharacter = CastChecked<AGASEBaseCharacter>(GetCharacter());

        Input->BindAction(InputData.MoveAction, ETriggerEvent::Triggered, GASEPlayerCharacter.Get(),
                          &AGASEBaseCharacter::MoveAction);
        Input->BindAction(InputData.LookAction, ETriggerEvent::Triggered, GASEPlayerCharacter.Get(),
                          &AGASEBaseCharacter::LookAction);
    }
}

void AGASEPlayerController::ControllerSetup()
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