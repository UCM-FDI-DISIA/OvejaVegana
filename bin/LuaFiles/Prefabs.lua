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
                    position = {0, 15, 50},
                    rotation ={180, 0, 90},
                    scale = {10, 10, 10}                   
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 0,
                    size = {9, 9, 9},
                    mass = 10.0,
                    friction = 0.5,
                    restitution = 0.0,
                    trigger = false,
                    mask = 2,
                    group = 1
                }
            },
            {
                name = "MovementComponent",
                parameters = {                  
                    
                }
            }, 
            {
                name = "EnemyChaseComponent",
                parameters = {                  
                    
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "enemigo.mesh",
                    entityname= "Enemy",
                    materialname = "enemigoMat"
                }
            }         
        }
    },  
    {   name = "Curacion",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = { 0, 100, 40},
                    rotation = {0, 0, 0},
                    scale = {20, 20, 20}                    
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
                    movementType = 1,
                    size = {10, 10, 10},
                    mass = 1.0,
                    friction = 1.0,
                    restitution = 1.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    modelname = "botiquin.mesh",
                    entityname= "cura",
                    materialname = "botiquinMat",
                    isstatic = false
                }
            },          
            {
                name = "HealComponent",
                parameters = {
                    amount = 1
                }
            }
        }
    }
}