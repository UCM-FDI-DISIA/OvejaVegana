Prefabs={
    {
        name = "PrefabBala",
        components = {
            {
                name = "Transform",
                parameters = {                  
                    position = {0, 0, 0},
                    rotation = {0, 0, 0},
                    scale = {1, 1, 1}     
                }
            },
            {
                name = "BulletComponent",
                parameters = {
                    speed = 10,
                    direction = {1, 0, 0}
                }
            },
            {
                name = "ColliderComponent",
                parameters = {
                }
            }       
        }
    }, 
    {  name = "PrefabCaja",
        components = {
	        {
                name = "Transform",
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
            }
            {
                name = "ColliderComponent",
                parameters = {
                }
            }
        }
    }
}