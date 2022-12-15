/*
 * scheduler.h
 *
 *  Created on: Dec 15, 2022
 *      Author: Vuong
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#define SCH_MAX_TASKS 40

void SCH_Update(void);
int SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks(void);
int SCH_Delete_Task(const int TASK_INDEX);

#endif /* INC_SCHEDULER_H_ */
