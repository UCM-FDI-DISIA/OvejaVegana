Entities={
    {
        name = "Player",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    position = {0, 10, 0},
                    rotation ={0, 0, 0},
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
                    size = {1, 1, 1},
                    mask = 3,
                    group = 2
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = true,
                    modelname = "enemigo.mesh",
                    entityname= "sinbad",
                    materialname = ""
                }
            },
            {
                name = "MovementComponent",
                parameters = {                  
                    
                }
            },
            {
                name = "CameraComponent",
                parameters = {                  
                    name = "anim",
                    color = {0.8, 0.3, 1},
                    alfa = 1,
                    offset = {100, 100, 100}
                }
            }                           
        }
    }, 
    {  
        name = "Light",
        components = {
	        {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {0, 30, 0},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "LightComponent",
                parameters = {
                    type = 1,
                    diffusecolour = {1, 1, 1},
                    shadowfardist = 25,
                    shadowdist = 25,
                    ineerangle = 90,
                    outerangle = 180,
                    nearclipdist = 0.1,
                    shdws = true
                }
	        }     
        }
    }, 
    {
        name = "Ogreman",
        components = {
            {
                name = "TransformComponent",
                parameters = {  
                    a = 0,
                    position = {0, 0, 20},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "MeshRenderComponent",
                parameters = {                  
                    isstatic = true,
                    modelname = "enemigo.mesh",
                    entityname= "sinbad",
                    materialname = ""
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
                    size = {300, 10, 300},
                    mask = 1,
                    group = 1
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