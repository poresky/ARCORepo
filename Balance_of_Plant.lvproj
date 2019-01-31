<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="17008000">
	<Property Name="varPersistentID:{1272C918-97F8-49AB-97B0-382D81688D04}" Type="Ref">/My Computer/BoP Libraries/BoPInputs.lvlib/Shaft RPM</Property>
	<Property Name="varPersistentID:{1B39138B-682B-4554-B55B-D8DEC281B744}" Type="Ref">/My Computer/BoP Libraries/BoPOutputs.lvlib/Compressor Temperature Out</Property>
	<Property Name="varPersistentID:{1EA96E21-E785-47A5-B4D8-07A6BAF7B075}" Type="Ref">/My Computer/BoP Libraries/BoPOutputs.lvlib/CTAH 1 Temperature Out</Property>
	<Property Name="varPersistentID:{24CE2595-97A3-4102-9F09-0E664ADECA98}" Type="Ref">/My Computer/BoP Libraries/BoPOutputs.lvlib/CTAH 2 Temperature Out</Property>
	<Property Name="varPersistentID:{3B894C9E-88A6-4CBB-8E7A-8024B8A4FC9F}" Type="Ref">/My Computer/BoP Libraries/BoPOutputs.lvlib/HPT Temp Out</Property>
	<Property Name="varPersistentID:{3D7B5946-FEC7-4208-BFCA-B4C25684A465}" Type="Ref">/My Computer/BoP Libraries/BoPOutputs.lvlib/CTAH 1 Pressure Out</Property>
	<Property Name="varPersistentID:{4B71603E-090D-408A-B3C0-4E1A77ACD055}" Type="Ref">/My Computer/BoP Libraries/BoPInputs.lvlib/NG Flow Rate</Property>
	<Property Name="varPersistentID:{6993CC80-5ADF-469A-9042-4942F3CE17E8}" Type="Ref">/My Computer/BoP Libraries/BoPInputs.lvlib/Ambient Pressure</Property>
	<Property Name="varPersistentID:{70CB331E-9640-4776-A583-E763F44F383F}" Type="Ref">/My Computer/BoP Libraries/BoPInputs.lvlib/CTAH 1 Heat Transfer Rate</Property>
	<Property Name="varPersistentID:{886B4F7F-3D55-4524-89D5-52194817CAE9}" Type="Ref">/My Computer/BoP Libraries/BoPOutputs.lvlib/LPT Work Out</Property>
	<Property Name="varPersistentID:{A06D864F-B531-44E6-80DD-89AC4DD7A1D0}" Type="Ref">/My Computer/BoP Libraries/BoPOutputs.lvlib/Compressor Pressure Out</Property>
	<Property Name="varPersistentID:{B412066E-0703-4218-8BE2-8A7AE46924F0}" Type="Ref">/My Computer/BoP Libraries/BoPInputs.lvlib/Ambient Temperature</Property>
	<Property Name="varPersistentID:{B5217B2F-2B55-4E7B-9FCA-EAB64CA59993}" Type="Ref">/My Computer/BoP Libraries/BoPOutputs.lvlib/CTAH 2 Pressure Out</Property>
	<Property Name="varPersistentID:{B7F358F6-CF6C-4441-928C-CAC949B1B5C5}" Type="Ref">/My Computer/BoP Libraries/BoPOutputs.lvlib/HPT Pressure Out</Property>
	<Property Name="varPersistentID:{C835058C-5D92-4617-93B8-55467CCF2C44}" Type="Ref">/My Computer/BoP Libraries/BoPOutputs.lvlib/HPT Work Out</Property>
	<Property Name="varPersistentID:{D1689403-1DF7-4124-B32D-93ABF0F95DAF}" Type="Ref">/My Computer/BoP Libraries/BoPOutputs.lvlib/LPT Pressure Out</Property>
	<Property Name="varPersistentID:{D947E6FA-584A-453D-93BD-E54BE6D3D983}" Type="Ref">/My Computer/BoP Libraries/BoPOutputs.lvlib/LPT Temp In</Property>
	<Property Name="varPersistentID:{DCFBFFB8-45B3-4525-A13F-F1212088ACF8}" Type="Ref">/My Computer/BoP Libraries/BoPOutputs.lvlib/Compressor Work</Property>
	<Property Name="varPersistentID:{F1A578E0-0395-4A26-8E4A-6F8D49B56238}" Type="Ref">/My Computer/BoP Libraries/BoPInputs.lvlib/CTAH 2 Heat Transfer Rate</Property>
	<Property Name="varPersistentID:{FA37A436-7CF8-409B-BE96-B87464F32897}" Type="Ref">/My Computer/BoP Libraries/BoPOutputs.lvlib/LPT Temp Out</Property>
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="BoP Libraries" Type="Folder">
			<Item Name="BoPInputs.lvlib" Type="Library" URL="../BoPInputs.lvlib"/>
			<Item Name="BoPOutputs.lvlib" Type="Library" URL="../BoPOutputs.lvlib"/>
		</Item>
		<Item Name="BoP Input Client.vi" Type="VI" URL="../BoP Input Client.vi"/>
		<Item Name="BoP Output Client.vi" Type="VI" URL="../BoP Output Client.vi"/>
		<Item Name="BoP Read Client.vi" Type="VI" URL="../BoP Read Client.vi"/>
		<Item Name="BoP.vi" Type="VI" URL="../BoP.vi"/>
		<Item Name="Model_Ctrl_Example.vi" Type="VI" URL="../Model_Ctrl_Example.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="BuildHelpPath.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/BuildHelpPath.vi"/>
				<Item Name="Check Special Tags.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Check Special Tags.vi"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="Clear Timing Source.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/TimedLoop/scheduler/LVUserAPI/Clear Timing Source.vi"/>
				<Item Name="Convert property node font to graphics font.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Convert property node font to graphics font.vi"/>
				<Item Name="Create Timing Source.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/TimedLoop/scheduler/LVUserAPI/Create Timing Source.vi"/>
				<Item Name="Create_1kHz_TSource.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/TimedLoop/scheduler/LVUserAPI/_suppVIs/Create_1kHz_TSource.vi"/>
				<Item Name="Create_1MHz_TSource.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/TimedLoop/scheduler/LVUserAPI/_suppVIs/Create_1MHz_TSource.vi"/>
				<Item Name="Create_SoftwareTrigger_TSource.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/TimedLoop/scheduler/LVUserAPI/_suppVIs/Create_SoftwareTrigger_TSource.vi"/>
				<Item Name="Details Display Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Details Display Dialog.vi"/>
				<Item Name="DialogType.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/DialogType.ctl"/>
				<Item Name="DialogTypeEnum.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/DialogTypeEnum.ctl"/>
				<Item Name="Error Code Database.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Error Code Database.vi"/>
				<Item Name="ErrWarn.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/ErrWarn.ctl"/>
				<Item Name="eventvkey.ctl" Type="VI" URL="/&lt;vilib&gt;/event_ctls.llb/eventvkey.ctl"/>
				<Item Name="Find Tag.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Find Tag.vi"/>
				<Item Name="Fire Software-Triggered Timing Source.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/TimedLoop/scheduler/LVUserAPI/Fire Software-Triggered Timing Source.vi"/>
				<Item Name="Format Message String.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Format Message String.vi"/>
				<Item Name="General Error Handler Core CORE.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/General Error Handler Core CORE.vi"/>
				<Item Name="General Error Handler.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/General Error Handler.vi"/>
				<Item Name="Get String Text Bounds.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Get String Text Bounds.vi"/>
				<Item Name="Get Text Rect.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Get Text Rect.vi"/>
				<Item Name="GetHelpDir.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/GetHelpDir.vi"/>
				<Item Name="GetRTHostConnectedProp.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/GetRTHostConnectedProp.vi"/>
				<Item Name="Longest Line Length in Pixels.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Longest Line Length in Pixels.vi"/>
				<Item Name="LVBoundsTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVBoundsTypeDef.ctl"/>
				<Item Name="LVRectTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVRectTypeDef.ctl"/>
				<Item Name="NI_MIT.lvlib" Type="Library" URL="/&lt;vilib&gt;/Model Interface Toolkit/NI_MIT.lvlib"/>
				<Item Name="NIVeriStand_MdlWrap.dll" Type="Document" URL="/&lt;vilib&gt;/Model Interface Toolkit/data/NIVeriStand_MdlWrap.dll"/>
				<Item Name="Not Found Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Not Found Dialog.vi"/>
				<Item Name="Search and Replace Pattern.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Search and Replace Pattern.vi"/>
				<Item Name="Set Bold Text.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Set Bold Text.vi"/>
				<Item Name="Set String Value.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Set String Value.vi"/>
				<Item Name="Simple Error Handler.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Simple Error Handler.vi"/>
				<Item Name="Stop Timed Structure.vi" Type="VI" URL="/&lt;vilib&gt;/Platform/TimedLoop/scheduler/LVUserAPI/Stop Timed Structure.vi"/>
				<Item Name="TagReturnType.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/TagReturnType.ctl"/>
				<Item Name="Three Button Dialog CORE.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Three Button Dialog CORE.vi"/>
				<Item Name="Three Button Dialog.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Three Button Dialog.vi"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
			</Item>
			<Item Name="lvalarms.dll" Type="Document" URL="lvalarms.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="lvuste.dll" Type="Document" URL="lvuste.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
