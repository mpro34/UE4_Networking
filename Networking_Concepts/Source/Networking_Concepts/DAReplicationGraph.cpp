// Fill out your copyright notice in the Description page of Project Settings.


#include "DAReplicationGraph.h"

void UDAReplicationGraph::InitGlobalGraphNodes()
{
	// Pre allocate some replication lists
	PreAllocateRepList(3, 12);
	PreAllocateRepList(6, 12);
	PreAllocateRepList(128, 64);
	PreAllocateRepList(512, 16);

	// Create our grid node
	GridNode = CreateNewNode<UReplicationGraphNode_GridSpatialization2D>();
	GridNode->CellSize = GridCellSize;
	GridNode->SpatialBias = FVector2D(SpatialBiasX, SpatialBiasY);

	if (bDisableSpatialRebuilding)
	{
		GridNode->AddSpatialRebuildBlacklistClass(AActor::StaticClass());
	}

	AddGlobalGraphNode(GridNode);

	// Create our always relevant node
	AlwaysRelevantNode = CreateNewNode<UReplicationGraphNode_ActorList>();
	AddGlobalGraphNode(AlwaysRelevantNode);
}
