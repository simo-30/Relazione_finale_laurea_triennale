//varie macro di utilizzo generale, come i percorsi per i vari file

/* macro delle librerie, accessibili solo da file in una cartella diversa dalla libreria,
 * e di un livello superiore*/ 
#define PROCESS_H "../processo/process.h"
#define SETTING_H "../setting/setting.h"
#define UTILITY_H "../utility/utility.h"
#define PROCESS_LIST_H "../lista_processo/process_list.h"
#define STAT_H "../statistics/stat.h"

/* macro per le varie politiche di scheduling */
#define FCFS_H "../FCFS/fcfs.h"

/* macro per i file di setting */
#define SET_TEST "../setting/setting.txt"
#define SET_1 "../file/setting/set1.txt"
#define SET_2 "../file/setting/set2.txt"
#define SET_3 "../file/setting/set3.txt"

/* macro per i file con i risultati */
#define RESULT_TEST "../file/result/result_test.csv"
#define RES_FCFS_1 "../file/result/result_fcfs_set1.csv"
#define RES_FCFS_2 "../file/result/result_fcfs_set2.csv"
#define RES_FCFS_3 "../file/result/result_fcfs_set3.csv"

/* macro numeriche */
#define NUM_CICLI 100
