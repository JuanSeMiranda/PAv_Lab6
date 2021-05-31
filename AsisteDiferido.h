#ifndef ASISTEDIFERIDO
#define ASISTEDIFERIDO
#define MAX_LOGS 100
#include "estudiante.h"
#include "DtLog.h"

class AsisteDiferido{
	public:
		DtLog* logs[MAX_LOGS];
		Estudiante* estudiante;
	private:
		AsisteDiferido();
		AsisteDiferido(Estudiante* estudiante);	
		~AsisteDiferido();
};

#endif