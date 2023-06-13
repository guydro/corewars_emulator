#include "init_helper_functions.h"
#include "init.h"
#include "structs_and_libraries.h"
#include "globals.h"

void init_usr_input() {
    printf("Please enter the number of survivors per round: ");
    scanf("%" SCNd32, &team_count);
    printf("Please enter the number of rounds per round: ");
    scanf("%" SCNd32, &survivor_count);
}

void load_players() {
    // Init survivors
    init_survivor_and_team_count();
    if ((teams = malloc(sizeof(Team)*team_count)) == 0) {printf("Not enough memory."); exit(1);};
    if ((zombies = malloc(sizeof(Team)*zombie_count)) == 0) {printf("Not enough memory."); exit(1);}

    DIR* dir;
    struct dirent* entry;

    dir = opendir("./survivors");
    if(dir == NULL) {
        puts("Error reading survivors folder");
        exit(1);
    }

    int32_t current_segment = 1;
    int32_t current_team = 0;
    int32_t current_zombie_team = 0;

    while((entry = readdir(dir))) {
        if (entry->d_name[0] == '.') continue;
        DIR* team_dir;
        struct dirent* survivor_entry;

        char tpath[512];
        strcpy(tpath, "./survivors/");
        team_dir = opendir(strcat(tpath, entry->d_name));

        Team team;
        team.survivors[0].initiaized = false;
        team.survivors[1].initiaized = false;

        team.living_survivors[0] = false;
        team.living_survivors[1] = false;

        team.name = entry->d_name;

        team.points = 0;

        team.shared_memory_id = current_segment++;

        while((survivor_entry = readdir(team_dir))) {
            if (survivor_entry->d_name[0] == '.') continue;
            Survivor survivor;

            survivor.code = get_code(survivor_entry->d_name, entry->d_name);

            survivor.stack_id = current_segment++;

            add_survivor_to_team(&team, survivor);
        }

        if(entry->d_name[0] == 'Z') {
            team.is_zombie = true;
            zombies[current_zombie_team++] = team;
        }
        else {
            team.is_zombie = false;
            teams[current_team++] = team;
        }
    }

    closedir(dir);
}