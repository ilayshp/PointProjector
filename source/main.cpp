// classic API header files
#include "c4d_plugin.h"
#include "c4d_resource.h"

#include "wsPointProjector.h"
#include "main.h"

::Bool PluginStart()
{
	RegisterProjectorObject();
	ApplicationOutput("PointProjector 1.4.4"_s);
	return true;
}

void PluginEnd()
{
	// free resources
}

::Bool PluginMessage(::Int32 id, void* data)
{
	switch (id)
	{
		case C4DPL_INIT_SYS:
		{
			// load resources defined in the the optional "res" folder
			if (!g_resource.Init())
				return false;

			return true;
		}
	}

	return true;
}