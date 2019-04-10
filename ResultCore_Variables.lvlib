<?xml version='1.0' encoding='UTF-8'?>
<Library LVVersion="17008000">
	<Property Name="NI.Lib.Icon" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!(]!!!*Q(C=\&gt;7R=2MR%!81N=?"5Q&lt;/07RB7W!,&lt;'&amp;&lt;9+K1,7Q,&lt;)%N&lt;!NMA3X)DW?-RJ(JQ"I\%%Z,(@`BA#==ZB3RN;]28_,V7@PWW`:R`&gt;HV*SU_WE@\N_XF[3:^^TX\+2YP)D7K6;G-RV3P)R`ZS%=_]J'XP/5N&lt;XH,7V\SEJ?]Z#5P?=J4HP+5JTTFWS%0?=B$DD1G(R/.1==!IT.+D)`B':\B'2Z@9XC':XC':XBUC?%:HO%:HO&amp;R7QT0]!T0]!S0I4&lt;*&lt;)?=:XA-(]X40-X40-VDSGC?"GC4N9(&lt;)"D2,L;4ZGG?ZH%;T&gt;-]T&gt;-]T?.S.%`T.%`T.)^&lt;NF8J4@-YZ$S'C?)JHO)JHO)R&gt;"20]220]230[;*YCK=ASI2F=)1I.Z5/Z5PR&amp;)^@54T&amp;5TT&amp;5TQO&lt;5_INJ6Z;"[(H#&gt;ZEC&gt;ZEC&gt;Z$"(*ETT*ETT*9^B)HO2*HO2*(F.&amp;]C20]C2)GN4UE1:,.[:/+5A?0^NOS?UJ^3&lt;*\9B9GT@7JISVW7*NIFC&lt;)^:$D`5Q9TWE7)M@;V&amp;D,6;M29DVR]6#R],%GC47T9_/=@&gt;Z5V&gt;V57&gt;V5E&gt;V5(OV?^T[FTP?\`?YX7ZRP6\D=LH%_8S/U_E5R_-R$I&gt;$\0@\W/VW&lt;[_"\Y[X&amp;],0^^+,]T_J&gt;`J@_B_]'_.T`$KO.@I"XC-_N!!!!!!</Property>
	<Property Name="NI.Lib.SourceVersion" Type="Int">385908736</Property>
	<Property Name="NI.Lib.Version" Type="Str">1.0.0.0</Property>
	<Property Name="NI.LV.All.SourceOnly" Type="Bool">false</Property>
	<Item Name="Core Error Out_R" Type="Variable">
		<Property Name="featurePacks" Type="Str">Network</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:ElemSize" Type="Str">1</Property>
		<Property Name="Network:PointsPerWaveform" Type="Str">1</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!U-!!!!"=!A!!!!!!"!!R!5Q&gt;798*J97ZU!!%!!"=!A!!!!!!"!!1!!!!"!!!!!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="Desired Power_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">The desired steady-state power for the core. </Property>
		<Property Name="featurePacks" Type="Str">Description,Network,Real-Time Features</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="Real-Time Features:ApplyNetworkConfig" Type="Str">False</Property>
		<Property Name="Real-Time Features:BufferLength" Type="Str">1</Property>
		<Property Name="Real-Time Features:UseBuffering" Type="Str">False</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!F)1!!!"=!A!!!!!!"!!V!#1!'5WFO:WRF!!!"!!!!!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="Exit Profile_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">Exits the input power profile (the Operation Mode must be other than "Power Profile Input" or operation will remain in this state). </Property>
		<Property Name="featurePacks" Type="Str">Description,Network</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!B(1!!!"=!A!!!!!!"!!R!)1&gt;#&lt;W^M:7&amp;O!!%!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="Input Power Profile Array_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">List of input powers to form a dynamic power signal to be performed by CIET's core. Assume a constant frequency (check in Core.vi). </Property>
		<Property Name="featurePacks" Type="Str">Description,Network</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!""01!!!"=!A!!!!!!#!!V!#A!(4H6N:8*J9Q!=1%!!!@````]!!!^"=H*B?3"P:C"%&lt;X6C&lt;'5!!1!"!!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="Loop Period_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">Actual period of loop activity in the core module (ms); the module loop time is probably different and is set within Core.vi. </Property>
		<Property Name="featurePacks" Type="Str">Description,Network</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!H)Q!!!"=!A!!!!!!"!!N!"!!&amp;37ZU.D1!!1!!!!!!!!!!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="Output Current 1_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">Output current from power supply 1. </Property>
		<Property Name="featurePacks" Type="Str">Description,Network</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!J*1!!!"=!A!!!!!!"!!V!#A!'2'^V9GRF!!!"!!!!!!!!!!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="Output Current 2_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">Output current from power supply 2. </Property>
		<Property Name="featurePacks" Type="Str">Description,Network</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!J*1!!!"=!A!!!!!!"!!V!#A!'2'^V9GRF!!!"!!!!!!!!!!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="Output Voltage 1_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">Output voltage from power supply 1. </Property>
		<Property Name="featurePacks" Type="Str">Description,Network</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!J*1!!!"=!A!!!!!!"!!V!#A!'2'^V9GRF!!!"!!!!!!!!!!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="Output Voltage 2_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">Output voltage from power supply 2. </Property>
		<Property Name="featurePacks" Type="Str">Description,Network</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!J*1!!!"=!A!!!!!!"!!V!#A!'2'^V9GRF!!!"!!!!!!!!!!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="Power Input Signal_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">Signal given to core module; coerced desired power to be positive and less than a set upper bound (see Core.vi). </Property>
		<Property Name="featurePacks" Type="Str">Description,Network</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!F)1!!!"=!A!!!!!!"!!V!#1!'5WFO:WRF!!!"!!!!!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="Power Output On_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">Turn CIET's core on or off. </Property>
		<Property Name="featurePacks" Type="Str">Description,Network,Real-Time Features</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="Real-Time Features:UseBuffering" Type="Str">False</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!B(1!!!"=!A!!!!!!"!!R!)1&gt;#&lt;W^M:7&amp;O!!%!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="Power Output_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">Acutal power output from the core. </Property>
		<Property Name="featurePacks" Type="Str">Description,Network</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!F)1!!!"=!A!!!!!!"!!V!#1!'5WFO:WRF!!!"!!!!!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="Profile Step_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">Tracks the step count for the input power profile. </Property>
		<Property Name="featurePacks" Type="Str">Description,Network</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!D(Q!!!"=!A!!!!!!"!!N!!Q!&amp;37ZU-T)!!1!!!!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="Select Operation Mode_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">Choose the operation mode for the core (power supplies for CIET's heater); options available in the drop-down menu. </Property>
		<Property Name="featurePacks" Type="Str">Description,Network,Real-Time Features</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="Real-Time Features:ApplyNetworkConfig" Type="Str">False</Property>
		<Property Name="Real-Time Features:BufferLength" Type="Str">1</Property>
		<Property Name="Real-Time Features:UseBuffering" Type="Str">False</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!D(Q!!!"=!A!!!!!!"!!V!"A!'65FO&gt;$%W!!!"!!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="Shutdown_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">Shutdown CIET's core, typically only used in emergencies. Use the "Shutdown" operational mode otherwise after zeroing out the desired power and turning the core off. </Property>
		<Property Name="featurePacks" Type="Str">Description,Network</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!B(1!!!"=!A!!!!!!"!!R!)1&gt;#&lt;W^M:7&amp;O!!%!!!!!!!!!!!!!!!</Property>
	</Item>
	<Item Name="VISA Out_R" Type="Variable">
		<Property Name="Description:Description" Type="Str">VISA address in use. </Property>
		<Property Name="featurePacks" Type="Str">Description,Network</Property>
		<Property Name="Network:BuffSize" Type="Str">50</Property>
		<Property Name="Network:SingleWriter" Type="Str">True</Property>
		<Property Name="Network:UseBinding" Type="Str">False</Property>
		<Property Name="Network:UseBuffering" Type="Str">False</Property>
		<Property Name="numTypedefs" Type="UInt">0</Property>
		<Property Name="Path" Type="Str">/Supervisor.lvproj/CIET-PXIe/PXI_Libraries/ResultCore_Variables.lvlib/</Property>
		<Property Name="type" Type="Str">Network</Property>
		<Property Name="typeDesc" Type="Bin">&amp;Q#!!!!!!!)!"1!&amp;!!!-!%!!!@````]!!!!"!!%!!!!U-!!!!"=!A!!!!!!"!!R!5Q&gt;798*J97ZU!!%!!"=!A!!!!!!"!!1!!!!"!!!!!!!!!!!!!!!!!!!</Property>
	</Item>
</Library>
