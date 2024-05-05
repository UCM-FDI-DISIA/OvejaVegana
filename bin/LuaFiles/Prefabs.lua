Prefabs={
    {
        name = "PrefabBala",
        components = {
            {
                name = "TransformComponent",
                parameters = {          
                    position = {0, 0, 0},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}     
                }
            },
            {
                name = "BulletComponent",
                parameters = {
                }
            },
            {
                name = "ColliderComponent",
                parameters = {
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Crate.mesh",
                    materialname = "crate/CrateDarkWood"
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 0,
                    size = {1, 1, 1},
                    mass = 10.0,
                    friction = 0.5,
                    restitution = 0.0,
                    trigger = false,
                    mask = 8,
                    group = 8
                }
            }
            
        }
    }, 
    {  name = "PrefabCaja",
        components = {
	        {
                name = "TransformComponent",
                parameters = {
                    position = {0, 0, 0},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}
                }
	        },
            name = "MeshRenderComponent",
            parameters = {                  
                isstatic = true,
                modelname = "Crate.mesh",
                materialname = "crate/CrateDarkWood"
            },
            {
                name = "ColliderComponent",
                parameters = {
                }
            }
        }
    },
    {
        name = "PrefabEnemy",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {0, 0, 0},
                    rotation ={0, 0, 90},
                    scale = {10, 10, 10}                   
                }
            },
            {
                name = "ColliderComponent",
                parameters = {
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 0,
                    size = {2, 2, 2},
                    mass = 10.0,
                    friction = 0.5,
                    restitution = 0.0,
                    trigger = true,
                    mask = 2,
                    group = 1
                }
            },
            --{
                --name = "MovementComponent",
                --parameters = {                  
                    
                --}
            --}, 
            --{
                --name = "EnemyChaseComponent",
                --parameters = {                  
                    
               --}
            --},
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "enemigo.mesh",
                    entityname= "Enemy",
                    materialname = "enemigo"
                }
            }         
        }
    },  
    {  name = "PrefabCuracion",
        components = {
	        {
                name = "HealComponent",
                parameters = {
                    amount = 2
                }
	        },
            name = "MeshRenderComponent",
            parameters = {                  
                isstatic = true,
                modelname = "botiquin.mesh",
                materialname = "botiquin/botiquinMat"
            },
            {
                name = "ColliderComponent",
                parameters = {
                }
            }
        }
    },
}