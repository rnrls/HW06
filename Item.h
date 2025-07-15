// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h" // ��� �����߿� �� �Ʒ��� ��ġ�� �ʼ� !!


UCLASS(Blueprintable, BlueprintType) // UCLASS() - �𸮾� �������� ����� �� �ִ� Ŭ�������� ��Ÿ��. UCLASS() ��ũ�ΰ� �־�� �𸮾� ������ �� Ŭ������ �ν���.
class SPARTAPROJECT_API AItem : public AActor
{
	GENERATED_BODY() // GENERATED_BODY() - �𸮾� ������ �� Ŭ������ ��Ÿ�����͸� �����ϵ��� ������. �� ��ũ�ΰ� �־�� �𸮾� ������ �� Ŭ������ �ν���.
	
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

//������ - �޸𸮿� ����. �� �ѹ� ȣ��. 
// PostInitializeComponents() - ������ ������ ȣ��. ������Ʈ�� �� �ʱ�ȭ�� �Ŀ� ȣ���. ��ȣ�ۿ� ������Ʈ���� ������ �ְ�ޱ� ������Ʈ�� �ϼ��� ���� ȣ��
// BeginPlay() - ������ ���۵� �� ȣ��. ���Ͱ� ���ӿ� �߰��Ǹ� ȣ���. ��ġ(Spawn) ����
// Tick() - �� �����Ӹ��� ȣ��.	
// EndPlay() - ������ ���� �� ȣ��. ��������. ���� ��ȯ, �ı� D -> E 
// Destroyed() - ���Ͱ� �ı��� �� ȣ��. ���� �Ǳ� ������ ȣ���.