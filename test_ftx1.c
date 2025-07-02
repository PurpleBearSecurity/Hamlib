#include <stdio.h>
#include <stdlib.h>
#include "hamlib/rig.h"

int main()
{
    RIG *rig;
    int ret;

    printf("Testing FTX-1 implementation...\n");

    // Initialize hamlib
    rig_set_debug(RIG_DEBUG_NONE);

    // Create rig instance
    rig = rig_init(RIG_MODEL_FTX1);
    if (!rig) {
        printf("Failed to initialize FTX-1 rig\n");
        return 1;
    }

    printf("FTX-1 rig initialized successfully\n");
    printf("Model: %s\n", rig->caps->model_name);
    printf("Manufacturer: %s\n", rig->caps->mfg_name);
    printf("Version: %s\n", rig->caps->version);

    // Clean up
    rig_cleanup(rig);

    printf("Test completed successfully\n");
    return 0;
} 