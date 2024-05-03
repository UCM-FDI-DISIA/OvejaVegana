Entities={ 
    {
        name = "Player",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {0, 0, 50},
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
            {
                name = "MovementComponent",
                parameters = {                  
                    
                }
            },
            {
                name = "PlayerInputComponent",
                parameters = {                  
                    
                }
            },  
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "oveja.mesh",
                    entityname= "Player",
                    materialname = "oveja"
                }
            }         
        }
    }, 
    {
        name = "Enemy",
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
                    size = {2, 2, 2},
                    mass = 10.0,
                    friction = 0.5,
                    restitution = 0.0,
                    trigger = true,
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
                    materialname = "enemigo"
                }
            }         
        }
    }, 
    {
        name = "Camera",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {0, 0, 200},
                    rotation ={0, 0, 90},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "CameraComponent",
                parameters = {                  
                    name = "anim",
                    color = {0, 0, 0},
                    alfa = 0.0,
                    offset = {0, 0, 0}
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
        name = "Ogreman5",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {10, 0, -10},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = false,
                    modelname = "Sinbad.mesh",
                    entityname= "node",

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
                    movementType = 2,
                    size = {2, 2, 2},
                    mass = 1,
                    friction =1,
                    restitution=1,
                    trigger = false,
                    mask = 1,
                    group = 2
                }
            },
            {
                name="NodeComponent",
                parameters={
                    ispatrol=true,
                    cost=1.8,
                    hcost=1.8,
                    iswalkable=true,
                    id=3

                }

            },
            {
                name = "MovementComponent",
                parameters = {                  
                    
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
                name = "ColliderComponent",
                parameters = {                
                }
            },
            {
                name = "RigidbodyComponent",
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
                    position = {0, 245, 5},
                    rotation = {0, 0, 0},
                    scale = {10, 0.25, 1}                   
                }
            },
            {
                name = "ColliderComponent",
                parameters = {                
                }
            },
            {
                name = "RigidbodyComponent",
                parameters = {    
                    shapeType = SHAPES_BOX,
                    movementType = MOVEMENT_TYPE_STATIC,
                    size = {100, 5, 1},
                    mask = 1,
                    group = 1
                }
            },
            -- {para debug
            --     name = "MeshRenderComponent",
            --     parameters = {                  
            --         isstatic = false,
            --         modelname = "mapa1.mesh",
            --         entityname= "Mundo",
            --         materialname = "Black"
            --     }
            -- }
        }
    },
    {
        name = "WorldBoundsS",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {0, 0, 5},
                    rotation = {0, 0, 0},
                    scale = {10, 0.25, 1}                   
                }
            },
            {
                name = "ColliderComponent",
                parameters = {                
                }
            },
            {
                name = "RigidbodyComponent",
                parameters = {    
                    shapeType = SHAPES_BOX,
                    movementType = MOVEMENT_TYPE_STATIC,
                    size = {200, 5, 1},
                    mask = 1,
                    group = 1
                }
            }
            -- {para debug
            --     name = "MeshRenderComponent",
            --     parameters = {                  
            --         isstatic = false,
            --         modelname = "mapa1.mesh",
            --         entityname= "Mundo",
            --         materialname = "Black"
            --     }
            -- }
        }
    },
    {
        name = "WorldBoundsE",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {95, 250, 5},
                    rotation = {0, 0, 0},
                    scale = {0.25, 10, 1}                   
                }
            },
            {
                name = "ColliderComponent",
                parameters = {                
                }
            },
            {
                name = "RigidbodyComponent",
                parameters = {    
                    shapeType = SHAPES_BOX,
                    movementType = MOVEMENT_TYPE_STATIC,
                    size = {1, 5, 200},
                    mask = 1,
                    group = 1
                }
            }
            -- { para debug
            --     name = "MeshRenderComponent",
            --     parameters = {                  
            --         isstatic = false,
            --         modelname = "mapa1.mesh",
            --         entityname= "Mundo",
            --         materialname = "Black"
            --     }
            -- }
        }
    },
    {
        name = "WorldBoundsW",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-150, 250, 5},
                    rotation = {0, 0, 0},
                    scale = {0.25, 10, 1}                   
                }
            },
            {
                name = "ColliderComponent",
                parameters = {                
                }
            },
            {
                name = "RigidbodyComponent",
                parameters = {    
                    shapeType = SHAPES_BOX,
                    movementType = MOVEMENT_TYPE_STATIC,
                    size = {1, 5, 200},
                    mask = 1,
                    group = 1
                }
            }
            -- { para debug
            --     name = "MeshRenderComponent",
            --     parameters = {                  
            --         isstatic = false,
            --         modelname = "mapa1.mesh",
            --         entityname= "Mundo",
            --         materialname = "Black"
            --     }
            -- }
        }
    },
    {
        name = "Timer_Prueba",
        components = {
            {
                name = "UITransformComponent",
                parameters = {  
                    hidden = false,
                    position = {0.5, 0.5},
                    scale = {0.5, 0.5}                   
                }
            },
            {
                name = "UITextComponent",
                parameters = {   
                    name = "pruebaTimer",
                    font = "Mario",
                    caption = "hola",
                    zOrder = 7,
                    charHeight = 0.1,
                    color = {1, 0, 0}
                }
            },
            {
                name = "TimerComponent",
                parameters = {    
                    maxTime = 180
                }
            }
            -- {para debug
            --     name = "MeshRenderComponent",
            --     parameters = {                  
            --         isstatic = false,
            --         modelname = "mapa1.mesh",
            --         entityname= "Mundo",
            --         materialname = "Black"
            --     }
            -- }
        }
    }
}