Prefabs = {
    {
        name = "PrefabBala",
        components = {
            {
                name = "TransformComponent",
                parameters = {          
                    position = {0, 1500, 500},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}     
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Bala.mesh",
                    entityname= "Bala",
                    materialname = "Material_bala"
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
                    size = {3, 3, 3},
                    mass = 10.0,
                    friction = 0.5,
                    restitution = 0.0,
                    trigger = false,
                    mask = 4,
                    group = 1
                }
            },
            {
                name = "BulletComponent",
                parameters = {
                }
            },
            {
                name = "SmokeComponent",
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
                    position = {0, 500, 1500},
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
                    group = 6
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
            },
            {
                name = "LifeComponent",
                parameters ={
                    health = 3
                }
            }        
        }
    },
    {
        name = "PrefabSmoke",
        components = {
            {
                name = "TransformComponent",
                parameters = {          
                    position = {0, 0, 0},
                    rotation = {0, 0, 0},
                    scale = {5, 5, 5}
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Bala.mesh",
                    entityname= "Humos",
                    materialname = "SmokeEffect_T"
                }
            },
            {
                name = "SmokeEffect",
                parameters = {
                    particleSystemName = "HumoDisparo",
                    templateName = "SmokeEffect",
                    position = {0, 0, 0},
                    scale = {100, 100, 100},
                    color = {0, 0, 0, 0},
                    duration = 1,
                    density = 50
                }
            }

        }
    }
}