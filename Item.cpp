
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
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object); // 0�� ���Կ� ��Ƽ���� ����
	}	

	PrimaryActorTick.bCanEverTick = true; // Tick() �Լ��� ����ϰڴ�.
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


//������ - �޸𸮿� ����. �� �ѹ� ȣ��. 
// PostInitializeComponents() - ������ ������ ȣ��. ������Ʈ�� �� �ʱ�ȭ�� �Ŀ� ȣ���. ��ȣ�ۿ� ������Ʈ���� ������ �ְ�ޱ� ������Ʈ�� �ϼ��� ���� ȣ��
// BeginPlay() - ������ ���۵� �� ȣ��. ���Ͱ� ���ӿ� �߰��Ǹ� ȣ���. ��ġ(Spawn) ����
// Tick() - �� �����Ӹ��� ȣ��.	
// EndPlay() - ������ ���� �� ȣ��. ��������. ���� ��ȯ, �ı� D -> E 
// Destroyed() - ���Ͱ� �ı��� �� ȣ��. ���� �Ǳ� ������ ȣ���.
// 
// 
// OnConstruction() - ���Ͱ� ������ �� ȣ��. 
// PreInitializeComponents() - BeginPlay() ���� ȣ��. 
// PostInitializeComponents() - BeginPlay() ���Ŀ� ȣ��.

