cmake_minimum_required(VERSION 3.7)
if(CMAKE_VERSION VERSION_LESS "3.13")
	if (POLICY CMP0076)
		cmake_policy(SET CMP0076 OLD)
	endif()
        target_sources(wwhd_rando_t4b PRIVATE "filetypes/wiiurpx.cpp" "filetypes/yaz0.cpp" "filetypes/sarc.cpp" "filetypes/msbt.cpp" "filetypes/elf.cpp" "filetypes/events.cpp" "filetypes/bfres.cpp" "filetypes/jpc.cpp" "filetypes/dzx.cpp" "filetypes/charts.cpp" "filetypes/bflyt.cpp" "filetypes/dds.cpp" "filetypes/bflim.cpp" "filetypes/msbp.cpp" "filetypes/bdt.cpp" "filetypes/util/elfUtil.cpp" "filetypes/shared/lms.cpp")
else()
	cmake_policy(SET CMP0076 NEW)
        target_sources(wwhd_rando_t4b PRIVATE wiiurpx.cpp yaz0.cpp sarc.cpp msbt.cpp elf.cpp events.cpp bfres.cpp jpc.cpp dzx.cpp charts.cpp bflyt.cpp dds.cpp bflim.cpp msbp.cpp bdt.cpp util/elfUtil.cpp shared/lms.cpp)
endif()

add_subdirectory("texture")
add_subdirectory("subfiles")
