/** @file sys_main.c 
* @brief Application main file - Tarea Única de Contador (Puros IF)
*/

/* Include Files */
#include "sys_common.h"

/* USER CODE BEGIN (1) */
#include "gio.h"
#include "FreeRTOS.h"
#include "os_task.h"

// --- CONFIGURACIÓN ---
#define DELAY_MS 500  // Velocidad fija del contador
/* USER CODE END */

/* USER CODE BEGIN (2) */
void vTaskCounter(void *pvParameters);
void vApplicationIdleHook(void);
/* USER CODE END */

int main(void)
{
/* USER CODE BEGIN (3) */
    // 1. Inicialización del driver GIO (Aplica la configuración de HALCoGen)
    gioInit();

    // 2. CREACIÓN DE LA TAREA ÚNICA (Contador)
    if(xTaskCreate(vTaskCounter, "Task_Counter", 128, NULL, 1, NULL) != pdTRUE)
    {
        while(1); // Error al crear la tarea
    }

    // 3. Arrancar el planificador de FreeRTOS
    vTaskStartScheduler();

    while(1);
/* USER CODE END */
    return 0;
}

/* USER CODE BEGIN (4) */
// TAREA ÚNICA: El Contador BCD con IFs
void vTaskCounter(void *pvParameters)
{
    int8_t current_count = 0;

    while (1)
    {
        // CONTROL DE LOS 4 LEDS EN EL PUERTO A (Pines 0, 1, 2, 3)
        if (current_count == 0) {
            gioSetBit(gioPORTA, 0, 0); gioSetBit(gioPORTA, 1, 0); gioSetBit(gioPORTA, 2, 0); gioSetBit(gioPORTA, 3, 0);
        }
        if (current_count == 1) {
            gioSetBit(gioPORTA, 0, 1); gioSetBit(gioPORTA, 1, 0); gioSetBit(gioPORTA, 2, 0); gioSetBit(gioPORTA, 3, 0);
        }
        if (current_count == 2) {
            gioSetBit(gioPORTA, 0, 0); gioSetBit(gioPORTA, 1, 1); gioSetBit(gioPORTA, 2, 0); gioSetBit(gioPORTA, 3, 0);
        }
        if (current_count == 3) {
            gioSetBit(gioPORTA, 0, 1); gioSetBit(gioPORTA, 1, 1); gioSetBit(gioPORTA, 2, 0); gioSetBit(gioPORTA, 3, 0);
        }
        if (current_count == 4) {
            gioSetBit(gioPORTA, 0, 0); gioSetBit(gioPORTA, 1, 0); gioSetBit(gioPORTA, 2, 1); gioSetBit(gioPORTA, 3, 0);
        }
        if (current_count == 5) {
            gioSetBit(gioPORTA, 0, 1); gioSetBit(gioPORTA, 1, 0); gioSetBit(gioPORTA, 2, 1); gioSetBit(gioPORTA, 3, 0);
        }
        if (current_count == 6) {
            gioSetBit(gioPORTA, 0, 0); gioSetBit(gioPORTA, 1, 1); gioSetBit(gioPORTA, 2, 1); gioSetBit(gioPORTA, 3, 0);
        }
        if (current_count == 7) {
            gioSetBit(gioPORTA, 0, 1); gioSetBit(gioPORTA, 1, 1); gioSetBit(gioPORTA, 2, 1); gioSetBit(gioPORTA, 3, 0);
        }
        if (current_count == 8) {
            gioSetBit(gioPORTA, 0, 0); gioSetBit(gioPORTA, 1, 0); gioSetBit(gioPORTA, 2, 0); gioSetBit(gioPORTA, 3, 1);
        }
        if (current_count == 9) {
            gioSetBit(gioPORTA, 0, 1); gioSetBit(gioPORTA, 1, 0); gioSetBit(gioPORTA, 2, 0); gioSetBit(gioPORTA, 3, 1);
        }

        // INCREMENTAR CONTADOR
        current_count++;
        if (current_count > 9)
        {
            current_count = 0;
        }

        // ESPERAR 500ms
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void vApplicationIdleHook(void)
{
    // Vacío
}
/* USER CODE END */
