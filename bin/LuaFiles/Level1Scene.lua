Entities={
    {
        name = "Player",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {0, 0, 0},
                    rotation ={0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
           
  
            -- {
            --     name = "LightComponent",
            --     parameters = {
            --         type = 1,
            --         diffusecolour = {1, 1, 1},
            --         shadowfardist = 25,
            --         shadowdist = 25,
            --         ineerangle = 90,
            --         outerangle = 180,
            --         nearclipdist = 0.1,
            --         shdws = true
            --     }
	        -- },
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
                    mass = 1,
                    friction = 0,
                    restitution = 0,
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
                name = "PlayerInputComponent",
                parameters = {                  
                    
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
                    position = {0, 200, 0},
                    rotation ={0, 90, 0},
                    scale = {1, 1, 1}                   
                }
            },
           
            {
                name = "CameraComponent",
                parameters = {                  
                    name = "anim",
                    color = {0, 0, 0},
                    alfa = 0,
                    offset = {0, 0, 0}
                }
            },
            {
                name = "LightComponent",
                parameters = {
                    type = 1,
                    diffusecolour = {1, 1, 1},
                    shadowfardist = 25,
                    shadowdist = 100,
                    ineerangle = 90,
                    outerangle = 180,
                    nearclipdist = 0.1,
                    shdws = true
                }
	        }  ,
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
                    mass = 1,
                    friction = 0,
                    restitution = 0,
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
                name = "PlayerInputComponent",
                parameters = {                  
                    
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
                    entityname= "sinbad5",
                    materialname = "Sinbad/Gold"
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
                    rotation = {90, 0, 0},
                    scale = {10, 10, 10}                   
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
                    position = {0, 5, 100},
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
                name = "RigidbodyComponent",
                parameters = {    
                    shapeType = SHAPES_BOX,
                    movementType = MOVEMENT_TYPE_STATIC,
                    size = {100, 5, 1},
                    mask = 1,
                    group = 1
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
                    position = {0, 5, -100},
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
                name = "RigidbodyComponent",
                parameters = {    
                    shapeType = SHAPES_BOX,
                    movementType = MOVEMENT_TYPE_STATIC,
                    size = {200, 5, 1},
                    mask = 1,
                    group = 1
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
                    position = {100, 5, 0},
                    rotation = {90, 0, 0},
                    scale = {1, 1, 1}                   
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
        }
    },
    {
        name = "WorldBoundsW",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {-100, 5, 0},
                    rotation = {90, 0, 0},
                    scale = {1, 1, 1}                   
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
        }
    }
    
}