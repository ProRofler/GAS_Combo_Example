// GAS Example project

#pragma once

#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "CoreMinimal.h"

#include "GASEMainAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)                                                                   \
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)                                                         \
    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)                                                                       \
    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)                                                                       \
    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class GAS_COMBO_EXAMPLE_API UGASEMainAttributeSet : public UAttributeSet
{
    GENERATED_BODY()

  public:
    ATTRIBUTE_ACCESSORS(UGASEMainAttributeSet, Health);
    ATTRIBUTE_ACCESSORS(UGASEMainAttributeSet, MaxHealth);

  protected:
    UPROPERTY(BlueprintReadOnly, Category = "Main attributes")
    FGameplayAttributeData Health;

    UPROPERTY(BlueprintReadOnly, Category = "Main attributes")
    FGameplayAttributeData MaxHealth;
};
