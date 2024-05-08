Entities={ 
    {
        name = "Camera",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {-25, 125, 350},
                    rotation ={0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "CameraComponent",
                parameters = {                  
                    name = "camaraNivel2",
                    color = {0, 0, 0},
                    alfa = 0.0,
                    offset = {0, 0, 0},
                    zOrder = 2
                }
            },
            {
                name = "LightComponent",
                parameters = {
                    type = 1,
                    diffusecolour = {10, 10, 10},
                    shadowfardist = 25.0,
                    shadowdist = 100.0,
                    ineerangle = 90.0,
                    outerangle = 180.0,
                    nearclipdist = 0.1,
                    shdws = true
                }
	        }  
        }
    },
    {
        name = "Player",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {-25, 125, 40},
                    rotation ={180, 0, 90},
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
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "oveja.mesh",
                    entityname= "Player",
                    materialname = "OvejaMat"
                }
            },
            {
                name = "UITransformComponent",
                parameters = {    
                    position = { 0.5,0.0},   
                    scale = { 0.11,0.1},   
                    hidden = false   
                    
                }
            },
            {
                name = "UIProgressBarComponent",
                parameters = {             
                    maximo = 3.0,
                    progres = 3.0,
                    progressBarName = "progBar2",
                    frameMaterial = "",
                    contentMaterial = "UI/progressframe",
                    zOrder = 1                   
                }
            },
            {
                name = "PlayerShootComponent",
                parameters ={
        
               }
            },
            {
                name = "PlayerInputComponent",
                parameters = {                  
                    
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
        name = "World",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {0, 0, 0},
                    rotation = {0, 0, 180},
                    scale = {10, 10, 1}                   
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {    
                    shapeType = SHAPES_BOX,
                    movementType = MOVEMENT_TYPE_STATIC,
                    size = {100, 1, 100},
                    mask = 1,
                    group = 1
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "mapa1.mesh",
                    entityname= "Mundo",
                    materialname = ""
                }
            }
        }
    },
    {
        name = "WorldBoundsN",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-25, 230, 40},
                    rotation = {0, 0, 0},
                    scale = {6.5, 0.25, 1}                   
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 1,
                    size = {130, 5, 5},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
                
            }
        }
    },
    {
        name = "WorldBoundsS",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-25, 10, 40},
                    rotation = {0, 0, 0},
                    scale = {6.5, 0.25, 1}                   
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 1,
                    size = {130, 5, 5},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            }
        }
    },
    {
        name = "WorldBoundsE",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {80, 110, 40},
                    rotation = {0, 0, 0},
                    scale = {0.25, 6.6, 1}                   
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 1,
                    size = {5, 130, 5},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            }
        }
    },
    {
        name = "WorldBoundsW",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-140, 110, 40},
                    rotation = {0, 0, 0},
                    scale = {0.25, 6.6, 1}                   
                }
            },
            {
                name = "RigidBodyComponent",
                parameters = {
                    shapeType = 1,
                    movementType = 1,
                    size = {5, 130, 5},
                    mass = 100000.0,
                    friction =1.0,
                    restitution=1.0,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            }
        }
    },
    {
        name = "Timer_Prueba",
        components = {
            {
                name = "UITransformComponent",
                parameters = {  
                    hidden = false,
                    position = {0.0, 0.0},
                    scale = {0.6, 0.6}                   
                }
            },
            {
                name = "UITextComponent",
                parameters = {   
                    name = "timerNivel2",
                    font = "Mario",
                    caption = "hola",
                    zOrder = 7,
                    charHeight = 0.08,
                    color = {1, 0, 0}
                }
            },
            {
                name = "TimerComponent",
                parameters = {    
                    maxTime = 240
                }
            }

        }
    },
    {   name = "Curacion1",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = { 55, 60, 40},
                    rotation = {90, -90, 90},
                    scale = {7, 7, 7}                    
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
                    modelname = "Medkit.mesh",
                    entityname= "cura",
                    materialname = "MedkitMaterial",
                    isstatic = false
                }
            }
        }
    },
    {   name = "Curacion2",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = { -60, 180, 40},
                    rotation = {90, -90, 90},
                    scale = {7, 7, 7}                    
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
                    modelname = "Medkit.mesh",
                    entityname= "cura",
                    materialname = "MedkitMaterial",
                    isstatic = false
                }
            }
        }
    }
}