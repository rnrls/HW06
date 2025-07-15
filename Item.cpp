
#include "Item.h"


AItem::AItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneRoot);

//Game/Resources/Props/SM_Chair.SM_Chair'
//Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold'
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Chair.SM_Chair"));
	if(MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object); // 0번 슬롯에 머티리얼 적용
	}	

	PrimaryActorTick.bCanEverTick = true; // Tick() 함수를 사용하겠다.
	RotationSpeed = 90.0f; 
}


void AItem::BeginPlay()
{
	Super::BeginPlay();
	OnItemPickedUP();
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

void AItem::ResetActorPosition()
{
	SetActorLocation(FVector::ZeroVector);
}

float AItem::GetRotationSpeed()const
{
	return RotationSpeed;
}


//생성자 - 메모리에 생김. 딱 한번 호출. 
// PostInitializeComponents() - 생성자 다음에 호출. 컴포넌트가 다 초기화된 후에 호출됨. 상호작용 컴포넌트끼리 데이터 주고받기 컴포넌트가 완성된 직후 호출
// BeginPlay() - 게임이 시작될 때 호출. 액터가 게임에 추가되면 호출됨. 배치(Spawn) 직후
// Tick() - 매 프레임마다 호출.	
// EndPlay() - 게임이 끝날 때 호출. 게임종료. 레벨 전환, 파괴 D -> E 
// Destroyed() - 액터가 파괴될 때 호출. 삭제 되기 직전에 호출됨.
// 
// 
// OnConstruction() - 액터가 생성될 때 호출. 
// PreInitializeComponents() - BeginPlay() 전에 호출. 
// PostInitializeComponents() - BeginPlay() 이후에 호출.

