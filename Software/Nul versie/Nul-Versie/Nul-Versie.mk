##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Nul-Versie
ConfigurationName      :=Debug
WorkspacePath          :="C:/Users/marte/OneDrive/Documenten/Studie/HU/Thema opdracht devices/TekTeamOne/Software/Nul versie"
ProjectPath            :="C:/Users/marte/OneDrive/Documenten/Studie/HU/Thema opdracht devices/TekTeamOne/Software/Nul versie/Nul-Versie"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=marte
Date                   :=06/10/2016
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Nul-Versie.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  -lgdi32 -static-libgcc -static-libstdc++ 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../Catch/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/IRLed.cpp$(ObjectSuffix) $(IntermediateDirectory)/IRSensor.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/marte/OneDrive/Documenten/Studie/HU/Thema opdracht devices/TekTeamOne/Software/Nul versie/Nul-Versie/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/IRLed.cpp$(ObjectSuffix): IRLed.cpp $(IntermediateDirectory)/IRLed.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/marte/OneDrive/Documenten/Studie/HU/Thema opdracht devices/TekTeamOne/Software/Nul versie/Nul-Versie/IRLed.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IRLed.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IRLed.cpp$(DependSuffix): IRLed.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IRLed.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IRLed.cpp$(DependSuffix) -MM "IRLed.cpp"

$(IntermediateDirectory)/IRLed.cpp$(PreprocessSuffix): IRLed.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IRLed.cpp$(PreprocessSuffix) "IRLed.cpp"

$(IntermediateDirectory)/IRSensor.cpp$(ObjectSuffix): IRSensor.cpp $(IntermediateDirectory)/IRSensor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/marte/OneDrive/Documenten/Studie/HU/Thema opdracht devices/TekTeamOne/Software/Nul versie/Nul-Versie/IRSensor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IRSensor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IRSensor.cpp$(DependSuffix): IRSensor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IRSensor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IRSensor.cpp$(DependSuffix) -MM "IRSensor.cpp"

$(IntermediateDirectory)/IRSensor.cpp$(PreprocessSuffix): IRSensor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IRSensor.cpp$(PreprocessSuffix) "IRSensor.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


