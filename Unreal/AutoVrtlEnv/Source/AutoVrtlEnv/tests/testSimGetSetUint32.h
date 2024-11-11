// Copyright 2021 The MathWorks, Inc.

#pragma once

#include "Sim3dActor.h"
#include "testSimGetSetUint32.generated.h"

/**
 *
 */
UCLASS()
class AUTOVRTLENV_API AtestSimGetSetUint32 : public ASim3dActor
{
    GENERATED_BODY()


    void* SignalReader;
    void* SignalWriter;

public:
    // Sets default values for this actor's properties
    AtestSimGetSetUint32();

    virtual void Sim3dSetup() override;
    virtual void Sim3dRelease() override;
    virtual void Sim3dStep(float DeltaSeconds) override;
};