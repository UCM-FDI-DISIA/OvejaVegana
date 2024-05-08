Prefabs={
    {
        name = "PrefabBala",
        components = {
            {
                name = "TransformComponent",
                parameters = {          
                    position = {0, 15, 50},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}     
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
                    modelname = "Bala.mesh",
                    entityname= "Bala",
                    materialname = "Bala_Gold"
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 0,
                    size = {8, 8, 8},
                    mass = 10.0,
                    friction = 0.5,
                    restitution = 0.0,
                    trigger = false,
                    mask = 8,
                    group = 8
                }
            },
            {
                name = "BulletComponent",
                parameters = {
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
                    size = {8, 8, 8},
                    mass = 10.0,
                    friction = 0.5,
                    restitution = 0.0,
                    trigger = true,
                    mask = 1,
                    group = 2
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
    {   name = "PrefabCuracion",
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
                name = "HealComponent",
                parameters = {
                    amount = 1
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
                    trigger = true,
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
            }
        }
    }
}