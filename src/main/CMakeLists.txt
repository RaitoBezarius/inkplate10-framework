idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS "")

target_link_librairies(__idf_main libfib.a)
