#include <stdio.h>
#include <stdlib.h>

// OSPF Area Configuration
struct ospf_area_config {
    unsigned int areaid;
    int type;
};

// Base Protocol Structure
struct proto {
    int proto_id;
    char *name;
};

// OSPF Protocol Instance
struct proto_ospf {
    struct proto proto;
    int areano;
    unsigned int router_id;
};

// Add OSPF Area
void ospf_area_add(struct proto_ospf *po, struct ospf_area_config *ac) {
    printf("Adding OSPF Area %u\n", ac->areaid);
    po->areano++;
}

// Start OSPF
int ospf_start(struct proto *p) {
    struct proto_ospf *po = (struct proto_ospf *)p;
    printf("Starting OSPF with Router ID: %u\n", po->router_id);

    struct ospf_area_config backbone = {0, 1};
    ospf_area_add(po, &backbone);
    
    return 0;
}

int main() {
    // Define the Instance
    struct proto_ospf ospf_instance = {
        .router_id = 0x01020304,
        .areano = 0
    };
    
    ospf_start(&ospf_instance.proto);
    return EXIT_SUCCESS;
}