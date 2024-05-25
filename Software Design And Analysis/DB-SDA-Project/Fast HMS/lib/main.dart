import 'package:fast_hms/screens/home_screen.dart';
import 'package:flutter/material.dart';
import 'package:supabase_flutter/supabase_flutter.dart';

Future<void> main() async {
  WidgetsFlutterBinding.ensureInitialized();

  await Supabase.initialize(
    url: 'https://rxsqmwhuophzzhpqnvgq.supabase.co',
    anonKey:
        'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InJ4c3Ftd2h1b3BoenpocHFudmdxIiwicm9sZSI6ImFub24iLCJpYXQiOjE2Njg2OTQzMDIsImV4cCI6MTk4NDI3MDMwMn0.N6bnlxBTgurEa4WLrMnLDuanpv5KGGHLMwPmBSpxGes',
  );
  runApp(
    const MyApp(),
  );
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: homescreen(),
    );
  }
}
