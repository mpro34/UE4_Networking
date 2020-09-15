// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ReplicationGraph.h"
#include "DAReplicationGraph.generated.h"

class UReplicationGraphNode_ActorList;
class UReplicationGraphNode_GridSpatialization2D;

/**
 * @20 minutes on video
 */
UCLASS(Transient, config=Engine)
class NETWORKING_CONCEPTS_API UDAReplicationGraph : public UReplicationGraph
{
	GENERATED_BODY()

	// Begin UReplicationGraph implementation
	virtual void InitGlobalGraphNodes() override;

	/** 
	 *
	 * This is the most important node in the replication graph.
	 * Carves the map up into grids and determines if an actor should send network updates
	 * to a connection depending on the different pre-defined grids.
	 */
	UPROPERTY()
	UReplicationGraphNode_GridSpatialization2D* GridNode;

	UPROPERTY()
	UReplicationGraphNode_ActorList* AlwaysRelevantNode;

protected:
	float GridCellSize = 10000.0f;		// The size of one grid cell in the grid node
	float SpatialBiasX = -150000.0f;	// "Min X" for replication
	float SpatialBiasY = -200000.0f;	// "Min Y" for replication

	// Force rebuilding of spatialization tree, when disabled will clamp it instead.
	bool bDisableSpatialRebuilding = true;
	
};
