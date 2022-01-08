include(FindUnixCommands)

set(CMD "python3 ${MESHDRIVER} -n 7 5 9 --outDir ${OUTDIR} -s ${STENCILVAL} --bounds 0.0 0.4 0.0 0.4 0.0 0.4 --periodic false")
execute_process(COMMAND ${BASH} -c ${CMD} RESULT_VARIABLE RES)
if(RES)
  message(FATAL_ERROR "Mesh generation failed")
else()
  message("Mesh generation succeeded!")
endif()

execute_process(COMMAND ${EXENAME} RESULT_VARIABLE CMD_RESULT)
if(RES)
  message(FATAL_ERROR "run failed")
else()
  message("run succeeded!")
endif()
