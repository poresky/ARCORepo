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
		<Item Name="BoP.vi" Type="VI" URL="../BoP.vi"/>
		<Item Name="Overview.vi" Type="VI" URL="../Overview.vi"/>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
