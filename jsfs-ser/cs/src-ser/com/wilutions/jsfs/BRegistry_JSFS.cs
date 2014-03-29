using System;
using System.Collections.Generic;
using byps;

namespace com.wilutions.jsfs
{
	
	public class BRegistry_JSFS : BRegistry { 
	
		public BRegistry_JSFS()
			: base(BBinaryModel.MEDIUM) {}
		
		private static BRegisteredSerializer[] serializers = new BRegisteredSerializer[] {
			new BRegisteredSerializer(9906860, "com.wilutions.jsfs.BSerializer_9906860", com.wilutions.jsfs.BSerializer_9906860.instance),
			new BRegisteredSerializer(145996442, "com.wilutions.jsfs.BSerializer_145996442", com.wilutions.jsfs.BSerializer_145996442.instance),
			new BRegisteredSerializer(169662220, "com.wilutions.jsfs.BSerializer_169662220", com.wilutions.jsfs.BSerializer_169662220.instance),
			new BRegisteredSerializer(240503306, "com.wilutions.jsfs.BSerializer_240503306", com.wilutions.jsfs.BSerializer_240503306.instance),
			new BRegisteredSerializer(481066845, "com.wilutions.jsfs.BSerializer_481066845", com.wilutions.jsfs.BSerializer_481066845.instance),
			new BRegisteredSerializer(544795964, "com.wilutions.jsfs.BSerializer_544795964", com.wilutions.jsfs.BSerializer_544795964.instance),
			new BRegisteredSerializer(566696346, "com.wilutions.jsfs.BSerializer_566696346", com.wilutions.jsfs.BSerializer_566696346.instance),
			new BRegisteredSerializer(575037953, "com.wilutions.jsfs.BSerializer_575037953", com.wilutions.jsfs.BSerializer_575037953.instance),
			new BRegisteredSerializer(665368294, "com.wilutions.jsfs.BSerializer_665368294", com.wilutions.jsfs.BSerializer_665368294.instance),
			new BRegisteredSerializer(706034600, "com.wilutions.jsfs.BSerializer_706034600", com.wilutions.jsfs.BSerializer_706034600.instance),
			new BRegisteredSerializer(744806851, "com.wilutions.jsfs.BSerializer_744806851", com.wilutions.jsfs.BSerializer_744806851.instance),
			new BRegisteredSerializer(964561591, "com.wilutions.jsfs.BSerializer_964561591", com.wilutions.jsfs.BSerializer_964561591.instance),
			new BRegisteredSerializer(964561595, "com.wilutions.jsfs.BSerializer_964561595", com.wilutions.jsfs.BSerializer_964561595.instance),
			new BRegisteredSerializer(964561600, "com.wilutions.jsfs.BSerializer_964561600", com.wilutions.jsfs.BSerializer_964561600.instance),
			new BRegisteredSerializer(979378962, "com.wilutions.jsfs.BSerializer_979378962", com.wilutions.jsfs.BSerializer_979378962.instance),
			new BRegisteredSerializer(1032737639, "com.wilutions.jsfs.BSerializer_1032737639", com.wilutions.jsfs.BSerializer_1032737639.instance),
			new BRegisteredSerializer(1078989294, "com.wilutions.jsfs.BSerializer_1078989294", com.wilutions.jsfs.BSerializer_1078989294.instance),
			new BRegisteredSerializer(1090607752, "com.wilutions.jsfs.BSerializer_1090607752", com.wilutions.jsfs.BSerializer_1090607752.instance),
			new BRegisteredSerializer(1092766252, "com.wilutions.jsfs.BSerializer_1092766252", com.wilutions.jsfs.BSerializer_1092766252.instance),
			new BRegisteredSerializer(1100528120, "com.wilutions.jsfs.BSerializer_1100528120", com.wilutions.jsfs.BSerializer_1100528120.instance),
			new BRegisteredSerializer(1124739608, "com.wilutions.jsfs.BSerializer_1124739608", com.wilutions.jsfs.BSerializer_1124739608.instance),
			new BRegisteredSerializer(1131301080, "com.wilutions.jsfs.BSerializer_1131301080", com.wilutions.jsfs.BSerializer_1131301080.instance),
			new BRegisteredSerializer(1153231042, "com.wilutions.jsfs.BSerializer_1153231042", com.wilutions.jsfs.BSerializer_1153231042.instance),
			new BRegisteredSerializer(1274131736, "com.wilutions.jsfs.BSerializer_1274131736", com.wilutions.jsfs.BSerializer_1274131736.instance),
			new BRegisteredSerializer(1354059712, "com.wilutions.jsfs.BSerializer_1354059712", com.wilutions.jsfs.BSerializer_1354059712.instance),
			new BRegisteredSerializer(1366717454, "com.wilutions.jsfs.BSerializer_1366717454", com.wilutions.jsfs.BSerializer_1366717454.instance),
			new BRegisteredSerializer(1374008726, "com.wilutions.jsfs.BSerializer_1374008726", com.wilutions.jsfs.BSerializer_1374008726.instance),
			new BRegisteredSerializer(1381128722, "com.wilutions.jsfs.BSerializer_1381128722", com.wilutions.jsfs.BSerializer_1381128722.instance),
			new BRegisteredSerializer(1439246415, "com.wilutions.jsfs.BSerializer_1439246415", com.wilutions.jsfs.BSerializer_1439246415.instance),
			new BRegisteredSerializer(1542825705, "com.wilutions.jsfs.BSerializer_1542825705", com.wilutions.jsfs.BSerializer_1542825705.instance),
			new BRegisteredSerializer(1609273478, "com.wilutions.jsfs.BSerializer_1609273478", com.wilutions.jsfs.BSerializer_1609273478.instance),
			new BRegisteredSerializer(1733426638, "com.wilutions.jsfs.BSerializer_1733426638", com.wilutions.jsfs.BSerializer_1733426638.instance),
			new BRegisteredSerializer(1762179110, "com.wilutions.jsfs.BSerializer_1762179110", com.wilutions.jsfs.BSerializer_1762179110.instance),
			new BRegisteredSerializer(1815527676, "com.wilutions.jsfs.BSerializer_1815527676", com.wilutions.jsfs.BSerializer_1815527676.instance),
			new BRegisteredSerializer(1824869366, "com.wilutions.jsfs.BSerializer_1824869366", com.wilutions.jsfs.BSerializer_1824869366.instance),
			new BRegisteredSerializer(1833696176, "com.wilutions.jsfs.BSerializer_1833696176", com.wilutions.jsfs.BSerializer_1833696176.instance),
			new BRegisteredSerializer(1849102471, "com.wilutions.jsfs.BSerializer_1849102471", com.wilutions.jsfs.BSerializer_1849102471.instance),
			new BRegisteredSerializer(1888107655, "com.wilutions.jsfs.BSerializer_1888107655", com.wilutions.jsfs.BSerializer_1888107655.instance),
			new BRegisteredSerializer(1925305675, "com.wilutions.jsfs.BSerializer_1925305675", com.wilutions.jsfs.BSerializer_1925305675.instance),
		};
		protected override BRegisteredSerializer[] getSortedSerializers() {
			return serializers;
		}
	}
}
