Entities={
    {
        name = "MenuButton",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.4, 0.4},
                    scale = {0.2, 0.1},
                    hidden = false     
                }
            },
            -- {        
            --     name = "UISpriteRendererComponent",
            --     parameters = {
            --         name = "menu", 
            --         material = "menu", 
            --         zOrder = 1
            --     }
            -- },
            {
                name = "UITextComponent",
                parameters = {                  
                    name = "menubutton",
                    font = "Mario",
                    caption = "MENU",
                    zOrder = 3,
                    charHeight = 0.1,
                    color = {1.0,0.0,0.0} 
                }
            },
            {
                name = "MenuButtonComponent",
                parameters = {  
                                  
                }
            }
        }
    },
    {
        name = "ExitButton",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.4, 0.6},
                    scale = {0.2, 0.1},
                    hidden = false     
                }
            },        
            {
                name = "UITextComponent",
                parameters = {                  
                    name = "exitbutton",
                    font = "Mario",
                    caption = "EXIT",
                    zOrder = 3,
                    charHeight = 0.1,
                    color = {1.0,0.0,0.0} 
                }
            },
            {
                name = "ExitButtonComponent",
                parameters = {  
                                  
                }
            }
        }
    },
    {
        name = "Winner",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.3, 0.1},
                    scale = {0.4, 0.25},
                    hidden = false     
                }
            },        
            {        
                name = "UISpriteRendererComponent",
                parameters = {
                    name = "winner", 
                    material = "winner", 
                    zOrder = 1
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
                    position = {0.0, 0.0, 0.0},
                    rotation = {0.0, 0.0, 0.0},
                    scale = {1.0, 1.0, 1.0}      
                }
            },
            {
                name = "CameraComponent",
                parameters = {
                    name = "win",
                    color = {0.0, 1.0, 0.0},
                    offset = {0.0, 0.0, 0.0},
                    zOrder = 4
                }
            }
        }
    }
}