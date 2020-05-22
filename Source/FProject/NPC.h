﻿
#pragma once

#include "GameFramework/Character.h"
#include "NPC.generated.h"


// Макрос, необходимый для работы в UE Editor
UCLASS()
class FPROJECT_API ANPC : public ACharacter
{
	// Макрос, необходимый для функционирования внутри UE
	GENERATED_UCLASS_BODY()

	// Сообщение, которое выдаёт NPC
	// Доступно для редактирования в BP 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NPCMessage)
		FString NpcMessage;
	
	// Сфера взаимодействия игрока и NPC
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision) USphereComponent* ProxSphere;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision) TSubobjectPtr<class USphereComponent> ProxSphere;
		

	// Объявление сферы объёма границ
	UFUNCTION(BlueprintNativeEvent, Category = "Collision")
	
	// ANPC::Prox_Implementation, не ANPC::Prox()
	void Prox(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};