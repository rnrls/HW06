// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h" // 헤더 파일중에 맨 아래에 위치가 필수 !!


UCLASS(Blueprintable, BlueprintType) // UCLASS() - 언리얼 엔진에서 사용할 수 있는 클래스임을 나타냄. UCLASS() 매크로가 있어야 언리얼 엔진이 이 클래스를 인식함.
class SPARTAPROJECT_API AItem : public AActor
{
	GENERATED_BODY() // GENERATED_BODY() - 언리얼 엔진이 이 클래스의 메타데이터를 생성하도록 지시함. 이 매크로가 있어야 언리얼 엔진이 이 클래스를 인식함.
	
public:	
	AItem();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Properties")
	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure, Category = "Item|Properties")
	float GetRotationSpeed() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Item|Event")
	void OnItemPickedUP();


};

//생성자 - 메모리에 생김. 딱 한번 호출. 
// PostInitializeComponents() - 생성자 다음에 호출. 컴포넌트가 다 초기화된 후에 호출됨. 상호작용 컴포넌트끼리 데이터 주고받기 컴포넌트가 완성된 직후 호출
// BeginPlay() - 게임이 시작될 때 호출. 액터가 게임에 추가되면 호출됨. 배치(Spawn) 직후
// Tick() - 매 프레임마다 호출.	
// EndPlay() - 게임이 끝날 때 호출. 게임종료. 레벨 전환, 파괴 D -> E 
// Destroyed() - 액터가 파괴될 때 호출. 삭제 되기 직전에 호출됨.