Entities={
    {
        name = "PlayButton",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.5, 0.4},
                    scale = {0.1, 0.1},
                    hidden = false     
                }
            },
            {
                name = "UITextComponent",
                parameters = {                  
                    name = "playbutton",
                    font = "OvejaVegana",
                    caption = "PLAY",
                    zOrder = 3,
                    charHeight = 0.1,
                    color = {1.0,1.0,1.0} 
                }
            },
            {
                name = "PlayButtonComponent",
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
                    position = {0.5, 0.6},
                    scale = {0.1, 0.1},
                    hidden = false     
                }
            },
            {
                name = "UITextComponent",
                parameters = {                  
                    name = "exitbutton",
                    font = "OvejaVegana",
                    caption = "EXIT",
                    zOrder = 3,
                    charHeight = 0.1,
                    color = {1.0,1.0,1.0} 
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
        name = "MusicButton",
        components = {           
            {
                name = "UITransformComponent",
                parameters = {                  
                    position = {0.9, 0.1},
                    scale = {0.1, 0.1},
                    hidden = false     
                }
            },
            {
                name = "UITextComponent",
                parameters = {                  
                    name = "mute",
                    font = "OvejaVegana",
                    caption = "MUTE",
                    zOrder = 3,
                    charHeight = 0.1,
                    color = {1.0,1.0,1.0} 
                }
            },
            {
                name = "MusicButtonComponent",
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
                    a = 0,
                    position = {0.0, 0.0, 0.0},
                    rotation = {0.0, 0.0, 0.0},
                    scale = {1, 1, 1}                   
                }
            },
            {
                name = "CameraComponent",
                parameters = {
                    name = "menu",
                    color = {0.0, 0.0, 0.0},
                    offset = {0.0, 0.0, 0.0}
                }
            }
        }
    }
}