#
# OMNeT++/OMNEST Makefile for OverSim
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -I../../inet/src/networklayer/common -I../../inet/src/networklayer/rsvp_te -I../../inet/src/networklayer/icmpv6 -I../../inet/src/transport/tcp -I../../inet/src/networklayer/mpls -I../../inet/src/networklayer/ted -I../../inet/src/networklayer/contract -I../../inet/src/util -I../../inet/src/transport/contract -I../../inet/src/linklayer/mfcore -I../../inet/src/networklayer/ldp -I../../inet/src/applications/udpapp -I../../inet/src/networklayer/ipv4 -I../../inet/src/base -I../../inet/src/util/headerserializers -I../../inet/src/networklayer/ipv6 -I../../inet/src/transport/sctp -I../../inet/src/world -I../../inet/src/applications/pingapp -I../../inet/src/linklayer/contract -I../../inet/src/networklayer/arp -I../../inet/src/transport/udp -L/usr/lib -L../../inet/out/$(CONFIGNAME)/src -linet -KINET_PROJ=../../inet -- -lgmp
#

# Name of target to be created (-o option)
TARGET = OverSim$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I../../inet/src/networklayer/common \
    -I../../inet/src/networklayer/rsvp_te \
    -I../../inet/src/networklayer/icmpv6 \
    -I../../inet/src/transport/tcp \
    -I../../inet/src/networklayer/mpls \
    -I../../inet/src/networklayer/ted \
    -I../../inet/src/networklayer/contract \
    -I../../inet/src/util \
    -I../../inet/src/transport/contract \
    -I../../inet/src/linklayer/mfcore \
    -I../../inet/src/networklayer/ldp \
    -I../../inet/src/applications/udpapp \
    -I../../inet/src/networklayer/ipv4 \
    -I../../inet/src/base \
    -I../../inet/src/util/headerserializers \
    -I../../inet/src/networklayer/ipv6 \
    -I../../inet/src/transport/sctp \
    -I../../inet/src/world \
    -I../../inet/src/applications/pingapp \
    -I../../inet/src/linklayer/contract \
    -I../../inet/src/networklayer/arp \
    -I../../inet/src/transport/udp \
    -I. \
    -Iapplications \
    -Iapplications/denacastapp \
    -Iapplications/dht \
    -Iapplications/tierdummy \
    -Icommon \
    -Icommon/cbr \
    -Ioverlay \
    -Ioverlay/cdnp2ptracker \
    -Ioverlay/denacastoverlay \
    -Ioverlay/simplemesh \
    -Itier2 \
    -Itier2/camera \
    -Itier2/videoplayer \
    -Iunderlay \
    -Iunderlay/inetunderlay \
    -Iunderlay/simpleunderlay \
    -Iunderlay/singlehostunderlay \
    -Iunderlay/singlehostunderlay/stun

# Additional object and library files to link with
EXTRA_OBJS = -lgmp

# Additional libraries (-L, -l options)
LIBS = -L/usr/lib -L../../inet/out/$(CONFIGNAME)/src  -linet
LIBS += -Wl,-rpath,`abspath /usr/lib` -Wl,-rpath,`abspath ../../inet/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/applications/denacastapp/Chunk.o \
    $O/applications/denacastapp/Scheduling.o \
    $O/applications/denacastapp/DenaCastApp.o \
    $O/applications/denacastapp/BufferMap.o \
    $O/applications/denacastapp/VideoBuffer.o \
    $O/applications/denacastapp/LocalVariables.o \
    $O/applications/denacastapp/VideoFrame.o \
    $O/applications/dht/DHT.o \
    $O/applications/dht/DHTDataStorage.o \
    $O/applications/tierdummy/TierDummy.o \
    $O/common/SHA1.o \
    $O/common/ProxNodeHandle.o \
    $O/common/UnderlayConfigurator.o \
    $O/common/Nps.o \
    $O/common/FinisherModule.o \
    $O/common/PeerInfo.o \
    $O/common/GlobalTraceManager.o \
    $O/common/TransportAddress.o \
    $O/common/GlobalParameters.o \
    $O/common/ChurnGenerator.o \
    $O/common/NoChurn.o \
    $O/common/BaseRpc.o \
    $O/common/OverlayKey.o \
    $O/common/CoordinateSystem.o \
    $O/common/CryptoModule.o \
    $O/common/NeighborCache.o \
    $O/common/GenericPacketParser.o \
    $O/common/NodeHandle.o \
    $O/common/Vivaldi.o \
    $O/common/GlobalNodeList.o \
    $O/common/TopologyVis.o \
    $O/common/BootstrapList.o \
    $O/common/SVivaldi.o \
    $O/common/BaseApp.o \
    $O/common/BaseOverlay.o \
    $O/common/BinaryValue.o \
    $O/common/TraceChurn.o \
    $O/common/Vector2D.o \
    $O/common/GlobalStatistics.o \
    $O/common/RpcListener.o \
    $O/common/OverSimMessage.o \
    $O/common/DenaCastNoChurn.o \
    $O/common/IterativeLookup.o \
    $O/common/RecursiveLookup.o \
    $O/common/LifetimeChurn.o \
    $O/common/cnetcommbuffer.o \
    $O/common/RandomChurn.o \
    $O/common/ParetoChurn.o \
    $O/common/NodeVector.o \
    $O/common/cbr/yang.o \
    $O/common/cbr/CoordBasedRouting.o \
    $O/common/cbr/simplex.o \
    $O/common/cbr/CBR-DHT.o \
    $O/common/cbr/Landmark.o \
    $O/overlay/cdnp2ptracker/CDNP2PTracker.o \
    $O/overlay/denacastoverlay/ChunkPackets.o \
    $O/overlay/denacastoverlay/DenaCastOverlay.o \
    $O/overlay/simplemesh/SimpleMesh.o \
    $O/tier2/camera/MPEG4Camera.o \
    $O/tier2/camera/BaseCamera.o \
    $O/tier2/videoplayer/MPEG4Player.o \
    $O/tier2/videoplayer/BasePlayer.o \
    $O/underlay/inetunderlay/InetUnderlayConfigurator.o \
    $O/underlay/inetunderlay/InetInfo.o \
    $O/underlay/inetunderlay/InetUnderlayConfigurator2.o \
    $O/underlay/inetunderlay/AccessNet.o \
    $O/underlay/simpleunderlay/SimpleUDP.o \
    $O/underlay/simpleunderlay/SimpleInfo.o \
    $O/underlay/simpleunderlay/SimpleUnderlayConfigurator.o \
    $O/underlay/simpleunderlay/SimpleNodeEntry.o \
    $O/underlay/singlehostunderlay/RealworldApp.o \
    $O/underlay/singlehostunderlay/ZeroconfConnector.o \
    $O/underlay/singlehostunderlay/RealworldDevice.o \
    $O/underlay/singlehostunderlay/realtimescheduler.o \
    $O/underlay/singlehostunderlay/SingleHostUnderlayConfigurator.o \
    $O/underlay/singlehostunderlay/RealworldConnector.o \
    $O/underlay/singlehostunderlay/TunOutDevice.o \
    $O/underlay/singlehostunderlay/apptunoutscheduler.o \
    $O/underlay/singlehostunderlay/udpoutscheduler.o \
    $O/underlay/singlehostunderlay/tunoutscheduler.o \
    $O/underlay/singlehostunderlay/UdpOutDevice.o \
    $O/underlay/singlehostunderlay/stun/stun.o \
    $O/underlay/singlehostunderlay/stun/udp.o \
    $O/applications/denacastapp/VideoMessage_m.o \
    $O/applications/dht/DHTMessage_m.o \
    $O/common/GlobalTraceManager_m.o \
    $O/common/Nps_m.o \
    $O/common/OverSimMessage_m.o \
    $O/common/CommonMessages_m.o \
    $O/common/Churn_m.o \
    $O/common/ExtAPIMessages_m.o \
    $O/common/cbr/CoordMessages_m.o \
    $O/common/cbr/CBR-DHTMessage_m.o \
    $O/overlay/denacastoverlay/DenaCastOverlayMessage_m.o \
    $O/overlay/denacastoverlay/DenaCastTrackerMessage_m.o \
    $O/overlay/simplemesh/SimpleMeshMessage_m.o \
    $O/underlay/simpleunderlay/SimpleUDPPacket_m.o

# Message files
MSGFILES = \
    applications/denacastapp/VideoMessage.msg \
    applications/dht/DHTMessage.msg \
    common/GlobalTraceManager.msg \
    common/Nps.msg \
    common/OverSimMessage.msg \
    common/CommonMessages.msg \
    common/Churn.msg \
    common/ExtAPIMessages.msg \
    common/cbr/CoordMessages.msg \
    common/cbr/CBR-DHTMessage.msg \
    overlay/denacastoverlay/DenaCastOverlayMessage.msg \
    overlay/denacastoverlay/DenaCastTrackerMessage.msg \
    overlay/simplemesh/SimpleMeshMessage.msg \
    underlay/simpleunderlay/SimpleUDPPacket.msg

# Other makefile variables (-K)
INET_PROJ=../../inet

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# inserted from file 'makefrag':
INCLUDE_PATH += -I$(OMNETPP_ROOT)/src/sim/parsim -I/sw/include
LIBS += -L/sw/lib

# <<<
#------------------------------------------------------------------------------

# Main target
all: $(TARGET)

$(TARGET) : $O/$(TARGET)
	$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY:

.SUFFIXES: .cc

$O/%.o: %.cc
	@$(MKPATH) $(dir $@)
	$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	-rm -rf $O
	-rm -f OverSim OverSim.exe libOverSim.so libOverSim.a libOverSim.dll libOverSim.dylib
	-rm -f ./*_m.cc ./*_m.h
	-rm -f applications/*_m.cc applications/*_m.h
	-rm -f applications/denacastapp/*_m.cc applications/denacastapp/*_m.h
	-rm -f applications/dht/*_m.cc applications/dht/*_m.h
	-rm -f applications/tierdummy/*_m.cc applications/tierdummy/*_m.h
	-rm -f common/*_m.cc common/*_m.h
	-rm -f common/cbr/*_m.cc common/cbr/*_m.h
	-rm -f overlay/*_m.cc overlay/*_m.h
	-rm -f overlay/cdnp2ptracker/*_m.cc overlay/cdnp2ptracker/*_m.h
	-rm -f overlay/denacastoverlay/*_m.cc overlay/denacastoverlay/*_m.h
	-rm -f overlay/simplemesh/*_m.cc overlay/simplemesh/*_m.h
	-rm -f tier2/*_m.cc tier2/*_m.h
	-rm -f tier2/camera/*_m.cc tier2/camera/*_m.h
	-rm -f tier2/videoplayer/*_m.cc tier2/videoplayer/*_m.h
	-rm -f underlay/*_m.cc underlay/*_m.h
	-rm -f underlay/inetunderlay/*_m.cc underlay/inetunderlay/*_m.h
	-rm -f underlay/simpleunderlay/*_m.cc underlay/simpleunderlay/*_m.h
	-rm -f underlay/singlehostunderlay/*_m.cc underlay/singlehostunderlay/*_m.h
	-rm -f underlay/singlehostunderlay/stun/*_m.cc underlay/singlehostunderlay/stun/*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc applications/*.cc applications/denacastapp/*.cc applications/dht/*.cc applications/tierdummy/*.cc common/*.cc common/cbr/*.cc overlay/*.cc overlay/cdnp2ptracker/*.cc overlay/denacastoverlay/*.cc overlay/simplemesh/*.cc tier2/*.cc tier2/camera/*.cc tier2/videoplayer/*.cc underlay/*.cc underlay/inetunderlay/*.cc underlay/simpleunderlay/*.cc underlay/singlehostunderlay/*.cc underlay/singlehostunderlay/stun/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/applications/denacastapp/LocalVariables.o: applications/denacastapp/LocalVariables.cc \
	applications/denacastapp/VideoBuffer.h \
	applications/denacastapp/LocalVariables.h \
	applications/denacastapp/BufferMap.h \
	applications/denacastapp/Chunk.h \
	applications/denacastapp/VideoFrame.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/TransportAddress.h
$O/applications/denacastapp/VideoFrame.o: applications/denacastapp/VideoFrame.cc \
	applications/denacastapp/VideoFrame.h
$O/applications/denacastapp/Chunk.o: applications/denacastapp/Chunk.cc \
	applications/denacastapp/Chunk.h \
	applications/denacastapp/VideoFrame.h
$O/applications/denacastapp/VideoMessage_m.o: applications/denacastapp/VideoMessage_m.cc \
	applications/denacastapp/BufferMap.h \
	applications/denacastapp/Chunk.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	applications/denacastapp/VideoFrame.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	applications/denacastapp/VideoMessage_m.h \
	common/TransportAddress.h
$O/applications/denacastapp/VideoBuffer.o: applications/denacastapp/VideoBuffer.cc \
	applications/denacastapp/VideoBuffer.h \
	applications/denacastapp/BufferMap.h \
	applications/denacastapp/Chunk.h \
	applications/denacastapp/VideoFrame.h
$O/applications/denacastapp/BufferMap.o: applications/denacastapp/BufferMap.cc \
	applications/denacastapp/BufferMap.h
$O/applications/denacastapp/Scheduling.o: applications/denacastapp/Scheduling.cc \
	applications/denacastapp/LocalVariables.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	common/RecursiveLookup.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	applications/denacastapp/VideoFrame.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	applications/denacastapp/VideoBuffer.h \
	common/NodeVector.h \
	common/GlobalStatistics.h \
	common/RpcState.h \
	common/CommonMessages_m.h \
	applications/denacastapp/Chunk.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	applications/denacastapp/VideoMessage_m.h \
	common/BinaryValue.h \
	common/Vector2D.h \
	applications/denacastapp/DenaCastApp.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	applications/denacastapp/BufferMap.h \
	tier2/camera/BaseCamera.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	common/BaseRpc.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/applications/denacastapp/DenaCastApp.o: applications/denacastapp/DenaCastApp.cc \
	applications/denacastapp/LocalVariables.h \
	common/PeerInfo.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/oversim_mapset.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/GlobalNodeList.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	applications/denacastapp/VideoFrame.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	applications/denacastapp/VideoBuffer.h \
	common/ChurnGenerator.h \
	common/NodeVector.h \
	common/HashFunc.h \
	common/RpcState.h \
	common/GlobalStatistics.h \
	common/CommonMessages_m.h \
	applications/denacastapp/Chunk.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	applications/denacastapp/VideoMessage_m.h \
	common/Vector2D.h \
	applications/denacastapp/DenaCastApp.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	applications/denacastapp/BufferMap.h \
	tier2/camera/BaseCamera.h \
	common/oversim_byteswap.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	common/BaseRpc.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/applications/dht/DHT.o: applications/dht/DHT.cc \
	applications/dht/DHTDataStorage.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/oversim_mapset.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/SHA1.h \
	common/NodeVector.h \
	common/RpcState.h \
	common/GlobalStatistics.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	applications/dht/DHT.h \
	applications/dht/DHTMessage_m.h \
	common/BinaryValue.h \
	common/Vector2D.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	common/BaseOverlay.h \
	common/Comparator.h \
	common/BaseRpc.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/applications/dht/DHTDataStorage.o: applications/dht/DHTDataStorage.cc \
	common/NodeVector.h \
	applications/dht/DHTDataStorage.h \
	common/CommonMessages_m.h \
	common/hashWatch.h \
	common/InitStages.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/OverSimMessage.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/Comparator.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/ProxNodeHandle.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h
$O/applications/dht/DHTMessage_m.o: applications/dht/DHTMessage_m.cc \
	common/CommonMessages_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	applications/dht/DHTMessage_m.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/OverSimMessage.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h
$O/applications/tierdummy/TierDummy.o: applications/tierdummy/TierDummy.cc \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	common/RecursiveLookup.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeVector.h \
	applications/tierdummy/TierDummy.h \
	common/RpcState.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	common/BinaryValue.h \
	common/Vector2D.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/BaseRpc.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/common/SVivaldi.o: common/SVivaldi.cc \
	common/NeighborCache.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/oversim_mapset.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/SVivaldi.h \
	common/Vivaldi.h \
	common/CoordinateSystem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/HashFunc.h \
	common/Nps.h \
	common/NodeVector.h \
	common/RpcState.h \
	common/GlobalStatistics.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	common/Nps_m.h \
	common/cbr/simplex.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/GlobalStatisticsAccess.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/BaseRpc.h \
	common/cbr/yang.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/common/ParetoChurn.o: common/ParetoChurn.cc \
	common/ChurnGenerator.h \
	common/GlobalStatistics.h \
	common/UnderlayConfigurator.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/InitStages.h \
	common/oversim_mapset.h \
	common/ParetoChurn.h \
	common/GlobalStatisticsAccess.h \
	common/TransportAddress.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h \
	common/Churn_m.h
$O/common/FinisherModule.o: common/FinisherModule.cc \
	common/FinisherModule.h \
	common/GlobalStatistics.h \
	common/GlobalStatisticsAccess.h
$O/common/NeighborCache.o: common/NeighborCache.cc \
	common/PeerInfo.h \
	common/NeighborCache.h \
	common/hashWatch.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/cbr/CoordMessages_m.h \
	common/oversim_mapset.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/GlobalNodeList.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/Vivaldi.h \
	common/SVivaldi.h \
	common/CoordinateSystem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/ChurnGenerator.h \
	common/HashFunc.h \
	common/Nps.h \
	common/NodeVector.h \
	common/RpcState.h \
	common/GlobalStatistics.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	common/cbr/simplex.h \
	common/Nps_m.h \
	common/BinaryValue.h \
	common/Vector2D.h \
	common/GlobalStatisticsAccess.h \
	common/TransportAddress.h \
	common/GlobalNodeListAccess.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/BaseRpc.h \
	common/ProxNodeHandle.h \
	common/cbr/yang.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/common/LifetimeChurn.o: common/LifetimeChurn.cc \
	common/LifetimeChurn.h \
	common/ChurnGenerator.h \
	common/GlobalStatistics.h \
	common/UnderlayConfigurator.h \
	common/InitStages.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/oversim_mapset.h \
	common/GlobalStatisticsAccess.h \
	common/TransportAddress.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h \
	common/Churn_m.h
$O/common/SHA1.o: common/SHA1.cc \
	common/SHA1.h
$O/common/OverSimMessage.o: common/OverSimMessage.cc \
	common/OverSimMessage.h \
	common/cnetcommbuffer.h \
	common/OverSimMessage_m.h
$O/common/CryptoModule.o: common/CryptoModule.cc \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/oversim_mapset.h \
	common/OverlayAccess.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	$(INET_PROJ)/src/base/NotificationBoard.h \
	common/NodeVector.h \
	common/GlobalStatistics.h \
	common/RpcState.h \
	common/CommonMessages_m.h \
	common/cnetcommbuffer.h \
	common/InitStages.h \
	common/TopologyVis.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	common/GlobalStatisticsAccess.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	common/CryptoModule.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	common/BaseRpc.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/common/ExtAPIMessages_m.o: common/ExtAPIMessages_m.cc \
	common/CommonMessages_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/OverSimMessage.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/ExtAPIMessages_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h
$O/common/BaseApp.o: common/BaseApp.cc \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	common/UnderlayConfigurator.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/oversim_mapset.h \
	common/OverlayAccess.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/GlobalNodeList.h \
	common/UnderlayConfiguratorAccess.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/base/NotificationBoard.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/ChurnGenerator.h \
	common/HashFunc.h \
	common/NodeVector.h \
	common/GlobalStatistics.h \
	common/RpcState.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	common/GlobalStatisticsAccess.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/GlobalNodeListAccess.h \
	common/IterativeLookupConfiguration.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	common/BaseRpc.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	$(INET_PROJ)/src/applications/udpapp/UDPAppBase.h \
	common/RpcMacros.h
$O/common/RpcListener.o: common/RpcListener.cc \
	common/RpcState.h \
	common/CommonMessages_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/OverSimMessage.h \
	common/OverlayKey.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h
$O/common/RecursiveLookup.o: common/RecursiveLookup.cc \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	common/RecursiveLookup.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeVector.h \
	common/RpcState.h \
	common/CommonMessages_m.h \
	common/LookupListener.h \
	common/InitStages.h \
	common/TopologyVis.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	common/BaseRpc.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/common/Nps_m.o: common/Nps_m.cc \
	common/CommonMessages_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/Nps_m.h \
	common/oversim_mapset.h \
	common/BinaryValue.h \
	common/Vector2D.h \
	common/TransportAddress.h \
	common/OverSimMessage.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h
$O/common/TransportAddress.o: common/TransportAddress.cc \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/TransportAddress.h
$O/common/Vivaldi.o: common/Vivaldi.cc \
	common/NeighborCache.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/oversim_mapset.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/Vivaldi.h \
	common/SVivaldi.h \
	common/CoordinateSystem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/HashFunc.h \
	common/Nps.h \
	common/NodeVector.h \
	common/RpcState.h \
	common/GlobalStatistics.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	common/Nps_m.h \
	common/cbr/simplex.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/GlobalStatisticsAccess.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/BaseRpc.h \
	common/cbr/yang.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/common/UnderlayConfigurator.o: common/UnderlayConfigurator.cc \
	common/ChurnGenerator.h \
	common/HashFunc.h \
	common/GlobalStatistics.h \
	common/UnderlayConfigurator.h \
	common/InitStages.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/oversim_mapset.h \
	common/BinaryValue.h \
	common/GlobalStatisticsAccess.h \
	common/TransportAddress.h \
	common/GlobalNodeListAccess.h \
	common/OverlayKey.h \
	common/GlobalNodeList.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/oversim_byteswap.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/ChurnGeneratorAccess.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	common/NodeHandle.h
$O/common/Nps.o: common/Nps.cc \
	common/NeighborCache.h \
	common/UnderlayConfigurator.h \
	common/oversim_mapset.h \
	common/cbr/CoordBasedRouting.h \
	common/RpcListener.h \
	common/Vivaldi.h \
	common/HashFunc.h \
	common/Nps.h \
	common/GlobalStatistics.h \
	common/RpcState.h \
	common/InitStages.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	common/BaseRpc.h \
	common/cbr/yang.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/PeerInfo.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	underlay/simpleunderlay/SimpleNodeEntry.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/GlobalNodeList.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/SVivaldi.h \
	common/CoordinateSystem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	underlay/simpleunderlay/SimpleUDPPacket_m.h \
	underlay/simpleunderlay/SimpleInfo.h \
	common/cbr/Landmark.h \
	common/ChurnGenerator.h \
	common/NodeVector.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/TopologyVis.h \
	common/cbr/CoordBasedRoutingAccess.h \
	common/cbr/simplex.h \
	common/Nps_m.h \
	common/GlobalStatisticsAccess.h \
	common/TransportAddress.h \
	common/GlobalNodeListAccess.h \
	common/IterativeLookupConfiguration.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/RpcMacros.h
$O/common/BaseOverlay.o: common/BaseOverlay.cc \
	common/UnderlayConfigurator.h \
	common/oversim_mapset.h \
	common/UnderlayConfiguratorAccess.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	common/HashFunc.h \
	common/GlobalStatistics.h \
	common/RpcState.h \
	common/LookupListener.h \
	common/InitStages.h \
	common/BootstrapList.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	common/BinaryValue.h \
	common/Vector2D.h \
	$(INET_PROJ)/src/transport/contract/UDPSocket.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	common/BaseRpc.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	$(INET_PROJ)/src/applications/udpapp/UDPAppBase.h \
	common/BootstrapNodeHandle.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	common/GlobalParameters.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/GlobalNodeList.h \
	common/GlobalParametersAccess.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/NotificationBoard.h \
	common/IterativeLookup.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/ChurnGenerator.h \
	common/NodeVector.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/TopologyVis.h \
	common/GlobalStatisticsAccess.h \
	common/TransportAddress.h \
	common/GlobalNodeListAccess.h \
	common/IterativeLookupConfiguration.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/RpcMacros.h
$O/common/NodeHandle.o: common/NodeHandle.cc \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h \
	common/TransportAddress.h
$O/common/Churn_m.o: common/Churn_m.cc \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h \
	common/Churn_m.h \
	common/TransportAddress.h
$O/common/GlobalTraceManager.o: common/GlobalTraceManager.cc \
	common/GlobalTraceManager_m.h \
	common/ChurnGenerator.h \
	common/HashFunc.h \
	common/UnderlayConfigurator.h \
	common/InitStages.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/oversim_mapset.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/GlobalNodeListAccess.h \
	common/OverlayKey.h \
	common/UnderlayConfiguratorAccess.h \
	common/GlobalNodeList.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/oversim_byteswap.h \
	common/GlobalTraceManager.h \
	common/TraceChurn.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h
$O/common/ChurnGenerator.o: common/ChurnGenerator.cc \
	common/ChurnGenerator.h \
	common/UnderlayConfiguratorAccess.h \
	common/UnderlayConfigurator.h \
	common/InitStages.h
$O/common/BaseRpc.o: common/BaseRpc.cc \
	common/NeighborCache.h \
	common/UnderlayConfigurator.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/oversim_mapset.h \
	common/OverlayAccess.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/UnderlayConfiguratorAccess.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/Vivaldi.h \
	common/SVivaldi.h \
	common/CoordinateSystem.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/base/NotificationBoard.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/HashFunc.h \
	common/Nps.h \
	common/NodeVector.h \
	common/RpcState.h \
	common/GlobalStatistics.h \
	common/CommonMessages_m.h \
	common/cnetcommbuffer.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	common/cbr/simplex.h \
	common/Nps_m.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	common/BinaryValue.h \
	common/Vector2D.h \
	common/GlobalStatisticsAccess.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	common/CryptoModule.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/BaseRpc.h \
	common/ProxNodeHandle.h \
	common/cbr/yang.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/common/NodeVector.o: common/NodeVector.cc \
	common/NodeVector.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/Comparator.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/TransportAddress.h
$O/common/GlobalParameters.o: common/GlobalParameters.cc \
	common/GlobalParameters.h \
	common/OverlayKey.h
$O/common/RandomChurn.o: common/RandomChurn.cc \
	common/ChurnGenerator.h \
	common/RandomChurn.h \
	common/GlobalStatistics.h \
	common/UnderlayConfigurator.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/InitStages.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/GlobalStatisticsAccess.h \
	common/TransportAddress.h
$O/common/cnetcommbuffer.o: common/cnetcommbuffer.cc \
	common/cnetcommbuffer.h
$O/common/IterativeLookup.o: common/IterativeLookup.cc \
	common/UnderlayConfigurator.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	common/RecursiveLookup.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/IterativeLookup.h \
	common/NodeVector.h \
	common/RpcState.h \
	common/GlobalStatistics.h \
	common/CommonMessages_m.h \
	common/InitStages.h \
	common/LookupListener.h \
	common/TopologyVis.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	common/BaseOverlay.h \
	common/Comparator.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/BaseRpc.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/common/OverSimMessage_m.o: common/OverSimMessage_m.cc \
	common/OverSimMessage_m.h
$O/common/TopologyVis.o: common/TopologyVis.cc \
	common/PeerInfo.h \
	common/ChurnGenerator.h \
	common/HashFunc.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/InitStages.h \
	common/TopologyVis.h \
	common/oversim_mapset.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/GlobalNodeListAccess.h \
	common/GlobalNodeList.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h
$O/common/OverlayKey.o: common/OverlayKey.cc \
	common/SHA1.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/Comparator.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/BinaryValue.h \
	common/TransportAddress.h
$O/common/NoChurn.o: common/NoChurn.cc \
	common/ChurnGenerator.h \
	common/UnderlayConfigurator.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/InitStages.h \
	common/NoChurn.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/TransportAddress.h
$O/common/CommonMessages_m.o: common/CommonMessages_m.cc \
	common/OverSimMessage.h \
	common/OverlayKey.h \
	common/CommonMessages_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h \
	common/BinaryValue.h \
	common/Vector2D.h \
	common/TransportAddress.h
$O/common/ProxNodeHandle.o: common/ProxNodeHandle.cc \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/TransportAddress.h
$O/common/GlobalTraceManager_m.o: common/GlobalTraceManager_m.cc \
	common/GlobalTraceManager_m.h
$O/common/GenericPacketParser.o: common/GenericPacketParser.cc \
	common/GenericPacketParser.h \
	common/cnetcommbuffer.h \
	common/PacketParser.h
$O/common/GlobalNodeList.o: common/GlobalNodeList.cc \
	common/PeerInfo.h \
	common/BootstrapNodeHandle.h \
	common/hashWatch.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/oversim_mapset.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/GlobalNodeList.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/base/NotificationBoard.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/ChurnGenerator.h \
	common/HashFunc.h \
	common/NodeVector.h \
	common/GlobalStatistics.h \
	common/RpcState.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	common/BootstrapList.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	common/Vector2D.h \
	common/GlobalStatisticsAccess.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	common/BaseRpc.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/common/TraceChurn.o: common/TraceChurn.cc \
	common/PeerInfo.h \
	common/ChurnGenerator.h \
	common/HashFunc.h \
	common/UnderlayConfigurator.h \
	common/InitStages.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/oversim_mapset.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/GlobalNodeListAccess.h \
	common/OverlayKey.h \
	common/GlobalNodeList.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/oversim_byteswap.h \
	common/TraceChurn.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h
$O/common/BootstrapList.o: common/BootstrapList.cc \
	common/BootstrapNodeHandle.h \
	common/UnderlayConfigurator.h \
	common/hashWatch.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/oversim_mapset.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/UnderlayConfiguratorAccess.h \
	common/GlobalNodeList.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/ChurnGenerator.h \
	underlay/singlehostunderlay/ZeroconfConnector.h \
	common/HashFunc.h \
	common/NodeVector.h \
	common/RpcState.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	common/BootstrapList.h \
	common/BinaryValue.h \
	common/Vector2D.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	common/BaseRpc.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/common/DenaCastNoChurn.o: common/DenaCastNoChurn.cc \
	common/ChurnGenerator.h \
	common/UnderlayConfigurator.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/InitStages.h \
	common/DenaCastNoChurn.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/TransportAddress.h
$O/common/Vector2D.o: common/Vector2D.cc \
	common/Vector2D.h
$O/common/PeerInfo.o: common/PeerInfo.cc \
	common/PeerInfo.h
$O/common/CoordinateSystem.o: common/CoordinateSystem.cc \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/CoordinateSystem.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/TransportAddress.h
$O/common/GlobalStatistics.o: common/GlobalStatistics.cc \
	common/GlobalStatistics.h
$O/common/BinaryValue.o: common/BinaryValue.cc \
	common/BinaryValue.h
$O/common/cbr/yang.o: common/cbr/yang.cc \
	common/cbr/yang.h
$O/common/cbr/simplex.o: common/cbr/simplex.cc \
	common/NeighborCache.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/oversim_mapset.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/Vivaldi.h \
	common/SVivaldi.h \
	common/CoordinateSystem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/HashFunc.h \
	common/Nps.h \
	common/NodeVector.h \
	common/RpcState.h \
	common/GlobalStatistics.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	common/Nps_m.h \
	common/cbr/simplex.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/GlobalStatisticsAccess.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/BaseRpc.h \
	common/cbr/yang.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/common/cbr/CoordMessages_m.o: common/cbr/CoordMessages_m.cc \
	common/CommonMessages_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/cbr/CoordMessages_m.h \
	common/oversim_mapset.h \
	common/BinaryValue.h \
	common/Vector2D.h \
	common/TransportAddress.h \
	common/OverSimMessage.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h
$O/common/cbr/Landmark.o: common/cbr/Landmark.cc \
	common/NeighborCache.h \
	common/UnderlayConfigurator.h \
	common/oversim_mapset.h \
	common/RpcListener.h \
	common/Vivaldi.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	common/HashFunc.h \
	common/Nps.h \
	common/GlobalStatistics.h \
	common/RpcState.h \
	common/InitStages.h \
	common/BootstrapList.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	common/BaseRpc.h \
	common/cbr/yang.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	$(INET_PROJ)/src/base/BasicModule.h \
	common/BootstrapNodeHandle.h \
	common/PeerInfo.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	underlay/simpleunderlay/SimpleNodeEntry.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/GlobalNodeList.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/SVivaldi.h \
	common/CoordinateSystem.h \
	underlay/simpleunderlay/SimpleUDPPacket_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	$(INET_PROJ)/src/base/NotificationBoard.h \
	underlay/simpleunderlay/SimpleUnderlayConfigurator.h \
	underlay/simpleunderlay/SimpleInfo.h \
	common/cbr/Landmark.h \
	common/ChurnGenerator.h \
	common/NodeVector.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/TopologyVis.h \
	common/Nps_m.h \
	common/cbr/simplex.h \
	common/GlobalStatisticsAccess.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/BaseOverlay.h \
	common/Comparator.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/RpcMacros.h
$O/common/cbr/CoordBasedRouting.o: common/cbr/CoordBasedRouting.cc \
	common/PeerInfo.h \
	common/ChurnGenerator.h \
	common/HashFunc.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/InitStages.h \
	common/cbr/CoordBasedRouting.h \
	common/oversim_mapset.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/GlobalNodeListAccess.h \
	common/GlobalNodeList.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/oversim_byteswap.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h
$O/common/cbr/CBR-DHT.o: common/cbr/CBR-DHT.cc \
	common/NeighborCache.h \
	applications/dht/DHTDataStorage.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/cbr/CoordBasedRouting.h \
	common/oversim_mapset.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/Vivaldi.h \
	common/SVivaldi.h \
	common/CoordinateSystem.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/SHA1.h \
	common/HashFunc.h \
	common/Nps.h \
	common/NodeVector.h \
	common/RpcState.h \
	common/GlobalStatistics.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	common/cbr/CoordBasedRoutingAccess.h \
	common/cbr/simplex.h \
	common/Nps_m.h \
	applications/dht/DHTMessage_m.h \
	common/BinaryValue.h \
	common/Vector2D.h \
	common/GlobalStatisticsAccess.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/cbr/CBR-DHT.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	common/OverlayKey.h \
	common/cbr/CBR-DHTMessage_m.h \
	common/oversim_byteswap.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/BaseRpc.h \
	common/ProxNodeHandle.h \
	common/cbr/yang.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/common/cbr/CBR-DHTMessage_m.o: common/cbr/CBR-DHTMessage_m.cc \
	common/CommonMessages_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	applications/dht/DHTMessage_m.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/OverSimMessage.h \
	common/OverlayKey.h \
	common/cbr/CBR-DHTMessage_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h
$O/overlay/cdnp2ptracker/CDNP2PTracker.o: overlay/cdnp2ptracker/CDNP2PTracker.cc \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/oversim_mapset.h \
	overlay/cdnp2ptracker/CDNP2PTracker.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	overlay/denacastoverlay/DenaCastTrackerMessage_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeVector.h \
	common/RpcState.h \
	common/CommonMessages_m.h \
	common/InitStages.h \
	common/TopologyVis.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/BaseRpc.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/overlay/denacastoverlay/DenaCastTrackerMessage_m.o: overlay/denacastoverlay/DenaCastTrackerMessage_m.cc \
	common/CommonMessages_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/OverSimMessage.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	overlay/denacastoverlay/DenaCastTrackerMessage_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h
$O/overlay/denacastoverlay/DenaCastOverlayMessage_m.o: overlay/denacastoverlay/DenaCastOverlayMessage_m.cc \
	common/CommonMessages_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	overlay/denacastoverlay/DenaCastOverlayMessage_m.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/OverSimMessage.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h
$O/overlay/denacastoverlay/ChunkPackets.o: overlay/denacastoverlay/ChunkPackets.cc \
	applications/denacastapp/Chunk.h \
	applications/denacastapp/VideoFrame.h \
	overlay/denacastoverlay/ChunkPackets.h
$O/overlay/denacastoverlay/DenaCastOverlay.o: overlay/denacastoverlay/DenaCastOverlay.cc \
	applications/denacastapp/LocalVariables.h \
	common/PeerInfo.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	overlay/denacastoverlay/DenaCastOverlayMessage_m.h \
	common/RecursiveLookup.h \
	common/oversim_mapset.h \
	underlay/simpleunderlay/SimpleNodeEntry.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/GlobalNodeList.h \
	common/RpcListener.h \
	applications/denacastapp/VideoFrame.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	underlay/simpleunderlay/SimpleUDPPacket_m.h \
	underlay/simpleunderlay/SimpleInfo.h \
	applications/denacastapp/VideoBuffer.h \
	common/ChurnGenerator.h \
	common/NodeVector.h \
	common/HashFunc.h \
	common/RpcState.h \
	common/GlobalStatistics.h \
	common/CommonMessages_m.h \
	applications/denacastapp/Chunk.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	overlay/denacastoverlay/DenaCastOverlay.h \
	overlay/denacastoverlay/ChunkPackets.h \
	applications/denacastapp/VideoMessage_m.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	applications/denacastapp/DenaCastApp.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	applications/denacastapp/BufferMap.h \
	common/OverlayKey.h \
	tier2/camera/BaseCamera.h \
	common/oversim_byteswap.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	common/BaseRpc.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/overlay/simplemesh/SimpleMeshMessage_m.o: overlay/simplemesh/SimpleMeshMessage_m.cc \
	overlay/simplemesh/SimpleMeshMessage_m.h \
	common/CommonMessages_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/OverSimMessage.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeHandle.h
$O/overlay/simplemesh/SimpleMesh.o: overlay/simplemesh/SimpleMesh.cc \
	common/oversim_mapset.h \
	overlay/simplemesh/SimpleMesh.h \
	applications/denacastapp/VideoFrame.h \
	common/RpcListener.h \
	overlay/denacastoverlay/DenaCastTrackerMessage_m.h \
	applications/denacastapp/VideoBuffer.h \
	common/HashFunc.h \
	common/GlobalStatistics.h \
	common/RpcState.h \
	applications/denacastapp/Chunk.h \
	common/InitStages.h \
	overlay/denacastoverlay/ChunkPackets.h \
	applications/denacastapp/VideoMessage_m.h \
	common/BinaryValue.h \
	common/Vector2D.h \
	applications/denacastapp/DenaCastApp.h \
	common/OverlayKey.h \
	tier2/camera/BaseCamera.h \
	common/oversim_byteswap.h \
	common/BaseRpc.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/PeerInfo.h \
	applications/denacastapp/LocalVariables.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	common/OverSimMessage_m.h \
	overlay/denacastoverlay/DenaCastOverlayMessage_m.h \
	common/RecursiveLookup.h \
	underlay/simpleunderlay/SimpleNodeEntry.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/GlobalNodeList.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	underlay/simpleunderlay/SimpleUDPPacket_m.h \
	underlay/simpleunderlay/SimpleInfo.h \
	common/ChurnGenerator.h \
	common/NodeVector.h \
	overlay/simplemesh/SimpleMeshMessage_m.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	overlay/denacastoverlay/DenaCastOverlay.h \
	common/TopologyVis.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	applications/denacastapp/BufferMap.h \
	common/BaseOverlay.h \
	common/Comparator.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/RpcMacros.h
$O/tier2/camera/MPEG4Camera.o: tier2/camera/MPEG4Camera.cc \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/oversim_mapset.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	applications/denacastapp/VideoFrame.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeVector.h \
	tier2/camera/MPEG4Camera.h \
	common/GlobalStatistics.h \
	common/RpcState.h \
	common/CommonMessages_m.h \
	applications/denacastapp/Chunk.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	applications/denacastapp/VideoMessage_m.h \
	common/BinaryValue.h \
	common/Vector2D.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	applications/denacastapp/BufferMap.h \
	tier2/camera/BaseCamera.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/BaseRpc.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/tier2/camera/BaseCamera.o: tier2/camera/BaseCamera.cc \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	common/RecursiveLookup.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/NodeVector.h \
	common/RpcState.h \
	common/GlobalStatistics.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	tier2/camera/BaseCamera.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/BaseRpc.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/tier2/videoplayer/BasePlayer.o: tier2/videoplayer/BasePlayer.cc \
	applications/denacastapp/LocalVariables.h \
	tier2/videoplayer/BasePlayer.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	common/RecursiveLookup.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	applications/denacastapp/VideoFrame.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	applications/denacastapp/VideoBuffer.h \
	common/NodeVector.h \
	common/GlobalStatistics.h \
	common/RpcState.h \
	applications/denacastapp/Chunk.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	applications/denacastapp/VideoMessage_m.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	applications/denacastapp/BufferMap.h \
	tier2/camera/BaseCamera.h \
	common/BaseOverlay.h \
	common/Comparator.h \
	common/BaseRpc.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/tier2/videoplayer/MPEG4Player.o: tier2/videoplayer/MPEG4Player.cc \
	applications/denacastapp/LocalVariables.h \
	tier2/videoplayer/BasePlayer.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/OverSimMessage_m.h \
	common/RecursiveLookup.h \
	common/oversim_mapset.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	tier2/videoplayer/MPEG4Player.h \
	applications/denacastapp/VideoFrame.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	applications/denacastapp/VideoBuffer.h \
	common/NodeVector.h \
	common/GlobalStatistics.h \
	common/RpcState.h \
	applications/denacastapp/Chunk.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	applications/denacastapp/VideoMessage_m.h \
	common/BinaryValue.h \
	common/Vector2D.h \
	common/TransportAddress.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	applications/denacastapp/BufferMap.h \
	tier2/camera/BaseCamera.h \
	common/Comparator.h \
	common/BaseOverlay.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/BaseRpc.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/underlay/inetunderlay/AccessNet.o: underlay/inetunderlay/AccessNet.cc \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	underlay/inetunderlay/AccessNet.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/InitStages.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPRoute.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	$(INET_PROJ)/src/networklayer/ipv4/IRoutingTable.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceEntry.h
$O/underlay/inetunderlay/InetInfo.o: underlay/inetunderlay/InetInfo.cc \
	common/PeerInfo.h \
	underlay/inetunderlay/InetInfo.h
$O/underlay/inetunderlay/InetUnderlayConfigurator.o: underlay/inetunderlay/InetUnderlayConfigurator.cc \
	common/PeerInfo.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	underlay/inetunderlay/AccessNet.h \
	common/UnderlayConfigurator.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPRoute.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	underlay/inetunderlay/InetInfo.h \
	common/GlobalNodeList.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	underlay/inetunderlay/InetUnderlayConfigurator.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/base/NotificationBoard.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceEntry.h \
	common/ChurnGenerator.h \
	common/HashFunc.h \
	common/InitStages.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/StringConvert.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	common/oversim_byteswap.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/NodeHandle.h \
	$(INET_PROJ)/src/networklayer/ipv4/IRoutingTable.h
$O/underlay/inetunderlay/InetUnderlayConfigurator2.o: underlay/inetunderlay/InetUnderlayConfigurator2.cc \
	common/PeerInfo.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	underlay/inetunderlay/AccessNet.h \
	common/UnderlayConfigurator.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPRoute.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	underlay/inetunderlay/InetInfo.h \
	common/GlobalNodeList.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/base/NotificationBoard.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceEntry.h \
	underlay/inetunderlay/InetUnderlayConfigurator2.h \
	common/ChurnGenerator.h \
	common/HashFunc.h \
	common/InitStages.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/StringConvert.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	common/oversim_byteswap.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/NodeHandle.h \
	$(INET_PROJ)/src/networklayer/ipv4/IRoutingTable.h
$O/underlay/simpleunderlay/SimpleUnderlayConfigurator.o: underlay/simpleunderlay/SimpleUnderlayConfigurator.cc \
	common/PeerInfo.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	common/UnderlayConfigurator.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	underlay/simpleunderlay/SimpleNodeEntry.h \
	common/GlobalNodeList.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceToken.h \
	underlay/simpleunderlay/SimpleUDP.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	underlay/simpleunderlay/SimpleUDPPacket_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	$(INET_PROJ)/src/base/NotificationBoard.h \
	underlay/simpleunderlay/SimpleUnderlayConfigurator.h \
	underlay/simpleunderlay/SimpleInfo.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceEntry.h \
	common/ChurnGenerator.h \
	common/HashFunc.h \
	common/InitStages.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/StringConvert.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/NodeHandle.h \
	$(INET_PROJ)/src/base/BasicModule.h
$O/underlay/simpleunderlay/SimpleUDPPacket_m.o: underlay/simpleunderlay/SimpleUDPPacket_m.cc \
	$(INET_PROJ)/src/base/INETDefs.h \
	underlay/simpleunderlay/SimpleUDPPacket_m.h
$O/underlay/simpleunderlay/SimpleUDP.o: underlay/simpleunderlay/SimpleUDP.cc \
	$(INET_PROJ)/src/networklayer/icmpv6/ICMPv6Access.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPRoute.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/networklayer/contract/IPControlInfo.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6ControlInfo_m.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceToken.h \
	underlay/simpleunderlay/SimpleUDP.h \
	$(INET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceEntry.h \
	common/HashFunc.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPDatagram_m.h \
	common/GlobalStatistics.h \
	common/InitStages.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	$(INET_PROJ)/src/networklayer/ipv6/IPv6Datagram.h \
	$(INET_PROJ)/src/networklayer/icmpv6/ICMPv6Message_m.h \
	$(INET_PROJ)/src/networklayer/ipv4/ICMPMessage_m.h \
	$(INET_PROJ)/src/networklayer/ipv4/ICMPAccess.h \
	common/NodeHandle.h \
	common/PeerInfo.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	overlay/denacastoverlay/DenaCastOverlayMessage_m.h \
	common/OverSimMessage_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6ControlInfo.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	underlay/simpleunderlay/SimpleNodeEntry.h \
	common/OverSimMessage.h \
	$(INET_PROJ)/src/networklayer/ipv4/ICMPMessage.h \
	common/GlobalNodeList.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/icmpv6/ICMPv6.h \
	$(INET_PROJ)/src/base/NotificationBoard.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	underlay/simpleunderlay/SimpleUDPPacket_m.h \
	underlay/simpleunderlay/SimpleUDPPacket.h \
	underlay/simpleunderlay/SimpleInfo.h \
	common/ChurnGenerator.h \
	common/CommonMessages_m.h \
	$(INET_PROJ)/src/networklayer/ipv4/RoutingTableAccess.h \
	common/GlobalStatisticsAccess.h \
	common/TransportAddress.h \
	common/GlobalNodeListAccess.h \
	$(INET_PROJ)/src/networklayer/ipv6/RoutingTable6.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/networklayer/contract/IPControlInfo_m.h \
	$(INET_PROJ)/src/networklayer/ipv4/ICMP.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/ipv6/IPv6Datagram_m.h \
	$(INET_PROJ)/src/networklayer/ipv6/RoutingTable6Access.h \
	$(INET_PROJ)/src/networklayer/ipv4/IRoutingTable.h
$O/underlay/simpleunderlay/SimpleInfo.o: underlay/simpleunderlay/SimpleInfo.cc \
	common/PeerInfo.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	underlay/simpleunderlay/SimpleUDPPacket_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	underlay/simpleunderlay/SimpleNodeEntry.h \
	underlay/simpleunderlay/SimpleInfo.h
$O/underlay/simpleunderlay/SimpleNodeEntry.o: underlay/simpleunderlay/SimpleNodeEntry.cc \
	common/SHA1.h \
	$(INET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	common/InitStages.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	common/BinaryValue.h \
	underlay/simpleunderlay/SimpleNodeEntry.h \
	common/OverlayKey.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	underlay/simpleunderlay/SimpleUDP.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	underlay/simpleunderlay/SimpleUDPPacket_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h
$O/underlay/singlehostunderlay/UdpOutDevice.o: underlay/singlehostunderlay/UdpOutDevice.cc \
	$(INET_PROJ)/src/networklayer/ipv4/IPDatagram_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	underlay/singlehostunderlay/tunoutscheduler.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	underlay/singlehostunderlay/RealworldConnector.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	underlay/singlehostunderlay/UdpOutDevice.h \
	$(INET_PROJ)/src/transport/udp/UDPPacket_m.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	underlay/singlehostunderlay/RealworldDevice.h \
	common/PacketParser.h \
	$(INET_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceEntry.h \
	underlay/singlehostunderlay/realtimescheduler.h
$O/underlay/singlehostunderlay/realtimescheduler.o: underlay/singlehostunderlay/realtimescheduler.cc \
	underlay/singlehostunderlay/realtimescheduler.h
$O/underlay/singlehostunderlay/udpoutscheduler.o: underlay/singlehostunderlay/udpoutscheduler.cc \
	underlay/singlehostunderlay/udpoutscheduler.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	underlay/singlehostunderlay/realtimescheduler.h
$O/underlay/singlehostunderlay/RealworldConnector.o: underlay/singlehostunderlay/RealworldConnector.cc \
	$(INET_PROJ)/src/base/INETDefs.h \
	underlay/singlehostunderlay/RealworldConnector.h \
	common/PacketParser.h \
	underlay/singlehostunderlay/realtimescheduler.h
$O/underlay/singlehostunderlay/RealworldDevice.o: underlay/singlehostunderlay/RealworldDevice.cc \
	$(INET_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	underlay/singlehostunderlay/RealworldConnector.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	underlay/singlehostunderlay/RealworldDevice.h \
	common/PacketParser.h \
	underlay/singlehostunderlay/realtimescheduler.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceEntry.h
$O/underlay/singlehostunderlay/TunOutDevice.o: underlay/singlehostunderlay/TunOutDevice.cc \
	$(INET_PROJ)/src/networklayer/ipv4/IPDatagram_m.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	underlay/singlehostunderlay/tunoutscheduler.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	underlay/singlehostunderlay/RealworldConnector.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INET_PROJ)/src/transport/udp/UDPPacket_m.h \
	underlay/singlehostunderlay/TunOutDevice.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/transport/udp/UDPPacket.h \
	$(INET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	underlay/singlehostunderlay/RealworldDevice.h \
	common/PacketParser.h \
	$(INET_PROJ)/src/networklayer/contract/IPProtocolId_m.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceEntry.h \
	underlay/singlehostunderlay/realtimescheduler.h
$O/underlay/singlehostunderlay/apptunoutscheduler.o: underlay/singlehostunderlay/apptunoutscheduler.cc \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	underlay/singlehostunderlay/apptunoutscheduler.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	underlay/singlehostunderlay/realtimescheduler.h
$O/underlay/singlehostunderlay/RealworldApp.o: underlay/singlehostunderlay/RealworldApp.cc \
	$(INET_PROJ)/src/base/INETDefs.h \
	underlay/singlehostunderlay/tunoutscheduler.h \
	underlay/singlehostunderlay/RealworldApp.h \
	underlay/singlehostunderlay/RealworldConnector.h \
	common/PacketParser.h \
	underlay/singlehostunderlay/realtimescheduler.h
$O/underlay/singlehostunderlay/ZeroconfConnector.o: underlay/singlehostunderlay/ZeroconfConnector.cc \
	common/BootstrapNodeHandle.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	common/OverSimMessage_m.h \
	common/oversim_mapset.h \
	common/RecursiveLookup.h \
	common/OverSimMessage.h \
	common/AbstractLookup.h \
	common/GlobalNodeList.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	common/RpcListener.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	common/ChurnGenerator.h \
	common/HashFunc.h \
	common/NodeVector.h \
	underlay/singlehostunderlay/ZeroconfConnector.h \
	common/RpcState.h \
	common/CommonMessages_m.h \
	common/BaseApp.h \
	common/InitStages.h \
	common/TopologyVis.h \
	common/BootstrapList.h \
	common/Vector2D.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/GlobalNodeListAccess.h \
	common/IterativeLookupConfiguration.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	common/BaseOverlay.h \
	common/Comparator.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/BaseRpc.h \
	common/ProxNodeHandle.h \
	common/NodeHandle.h \
	common/RpcMacros.h
$O/underlay/singlehostunderlay/SingleHostUnderlayConfigurator.o: underlay/singlehostunderlay/SingleHostUnderlayConfigurator.cc \
	common/PeerInfo.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPv4InterfaceData.h \
	common/UnderlayConfigurator.h \
	$(INET_PROJ)/src/base/INotifiable.h \
	underlay/singlehostunderlay/stun/stun.h \
	$(INET_PROJ)/src/base/INETDefs.h \
	$(INET_PROJ)/src/networklayer/ipv4/IPRoute.h \
	common/oversim_mapset.h \
	$(INET_PROJ)/src/linklayer/contract/MACAddress.h \
	common/GlobalNodeList.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceToken.h \
	$(INET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INET_PROJ)/src/base/NotificationBoard.h \
	$(INET_PROJ)/src/base/ModuleAccess.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddress.h \
	$(INET_PROJ)/src/networklayer/common/InterfaceEntry.h \
	common/ChurnGenerator.h \
	common/HashFunc.h \
	underlay/singlehostunderlay/stun/stun_udp.h \
	common/InitStages.h \
	$(INET_PROJ)/src/base/NotifierConsts.h \
	common/BinaryValue.h \
	common/TransportAddress.h \
	common/GlobalNodeListAccess.h \
	$(INET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	common/OverlayKey.h \
	common/oversim_byteswap.h \
	$(INET_PROJ)/src/networklayer/contract/IPv6Address.h \
	common/NodeHandle.h \
	$(INET_PROJ)/src/base/BasicModule.h \
	underlay/singlehostunderlay/SingleHostUnderlayConfigurator.h \
	$(INET_PROJ)/src/networklayer/ipv4/IRoutingTable.h
$O/underlay/singlehostunderlay/tunoutscheduler.o: underlay/singlehostunderlay/tunoutscheduler.cc \
	underlay/singlehostunderlay/tunoutscheduler.h \
	underlay/singlehostunderlay/realtimescheduler.h
$O/underlay/singlehostunderlay/stun/stun.o: underlay/singlehostunderlay/stun/stun.cc \
	underlay/singlehostunderlay/stun/stun_udp.h \
	underlay/singlehostunderlay/stun/stun.h
$O/underlay/singlehostunderlay/stun/udp.o: underlay/singlehostunderlay/stun/udp.cc \
	underlay/singlehostunderlay/stun/stun_udp.h

